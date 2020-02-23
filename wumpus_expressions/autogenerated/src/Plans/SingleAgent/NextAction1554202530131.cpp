#include "Plans/SingleAgent/NextAction1554202530131.h"
using namespace alica;
/*PROTECTED REGION ID(eph1554202530131) ENABLED START*/ //Add additional using directives here
#include <wumpus/WumpusWorldModel.h>
#include <wumpus_msgs/AgentPerception.h>
#include <wumpus_msgs/Coordinates.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:NextAction

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1554202530133

     */
    shared_ptr<UtilityFunction> UtilityFunction1554202530131::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1554202530131) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: DetermineObjective in Plan: NextAction

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : determine obj success 
     *
     * Plans in State: 				
     *   - Plan - (Name): DetermineObjectiveDefault, (PlanID): 1554202577790 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1554202530133)
     *
     * States:
     *   - DetermineObjective (1554202530132)
     *   - PlanAndExecute (1554202945017)
     *   - Success (1554202959483)
     *
     * Vars:
     */
    bool TransitionCondition1554202971930::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1554202970601) ENABLED START*/
        return rp->isAnyChildStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: PlanAndExecute in Plan: NextAction

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : success or timeout
     *
     * Plans in State: 				
     *   - Plan - (Name): PerformActionDefault, (PlanID): 1534836780649 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1554202530133)
     *
     * States:
     *   - DetermineObjective (1554202530132)
     *   - PlanAndExecute (1554202945017)
     *   - Success (1554202959483)
     *
     * Vars:
     */
    bool TransitionCondition1554203054731::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1554203053575) ENABLED START*/
        auto timeout = (rp->getAlicaEngine()->getAlicaClock()->now().inSeconds() - rp->getStateStartTime().inSeconds()) > this->wm->timeoutDurationSeconds;
        if (timeout) {
            std::cout << "TIMEOUT!!!" << std::endl;
            this->wm->experiment->getCurrentRun()->getCurrentResult()->completionStatus = eval::CompletionStatus::TIMEOUT;
            this->wm->communication->sendTimeoutMessage();
            this->wm->setIsTimeout();
            wumpus_msgs::AgentPerception agentPerception;
            agentPerception.died = true;
            wumpus_msgs::Coordinates pos;
            pos.x = -1;
            pos.y = -1;
            agentPerception.position = pos;
            agentPerception.initialPosition = pos;
            this->wm->sendAgentPerception(agentPerception);
        }

        return timeout || rp->isAnyChildStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

//State: Success in Plan: NextAction

}
