#pragma once
#include "DomainElement.h"
#include <map>
#include <memory>
#include <mutex>
#include <utility> //pair
#include <nonstd/optional.hpp>

namespace wumpus
{
class WumpusWorldModel;
namespace model
{
class Agent;
class Field;
class Playground : public wumpus::model::DomainElement
{
public:
    Playground(wumpus::wm::ChangeHandler* ch);
    virtual ~Playground();
    void initializePlayground(int playgroundSize);
    void addAgent(std::shared_ptr<wumpus::model::Agent> agent);
    void addAgentForExperiment(std::shared_ptr<wumpus::model::Agent> agent);
    void removeAgent(int id);
    void handleSilence();
    void handleScream();
    std::shared_ptr<wumpus::model::Agent> getAgentById(int id);
    std::shared_ptr<std::map<int,std::shared_ptr<wumpus::model::Agent>>> getAgents(bool expectAll);
    std::shared_ptr<std::map<int,std::shared_ptr<wumpus::model::Agent>>> getAgentsForExperiment();
    std::shared_ptr<wumpus::model::Field> getField(int x, int y);
    std::vector<std::shared_ptr<wumpus::model::Field>> getAdjacentFields(int x, int y);
    int getPlaygroundSize();
    nonstd::optional<int> getOwnAgentIndex();
    int getNumberOfAgents();
    int getNumberOfFields();

private:
    long turnCounter;
    int playgroundSize;
    //currently active agents
    std::map<int, std::shared_ptr<wumpus::model::Agent>> agents;
    //all agents who ever participated in the experiment
    std::map<int, std::shared_ptr<wumpus::model::Agent>> agentsForExperiment;
    std::map<std::pair<int, int>, std::shared_ptr<wumpus::model::Field>> fields;
    static std::mutex agentMtx;
    static std::mutex fieldMtx;
};

} /* namespace model */
} /* namespace wumpus */
