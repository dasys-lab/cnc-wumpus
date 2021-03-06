#pragma once
#include "Strategy.h"
#include "TermManager.h"
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <engine/AlicaEngine.h>
#include <mutex>
#include <reasoner/asp/ExtensionQuery.h>
#include <reasoner/asp/Solver.h>
#include <vector>

namespace aspkb
{
class Extractor
{
public:
    Extractor();

    ~Extractor();

//    void initializeSolver(::reasoner::asp::Solver* solver);
//
//    std::vector<std::string> extractTemporaryQueryResult(std::vector<std::string> inquiryPredicates, const std::vector<std::string>& additionalRules,
//            const std::pair<std::string, std::string>& horizonParam);

    std::vector<std::string> extractReusableTemporaryQueryResult(const std::vector<std::string>& inquiryPredicates, const std::string& queryIdentifier, const std::vector<std::string>& additionalRules);

    std::vector<std::string> solveWithIncrementalExtensionQuery(std::vector<std::string> inquiryPredicates, const std::vector<std::string>& baseRules,
            const std::vector<std::string>& stepRules, const std::vector<std::string>& checkRules, int maxHorizon);

private:
    ::reasoner::asp::Solver* solver;

    //std::map<int, std::shared_ptr<::reasoner::asp::ReusableExtensionQuery>> checkQueries; //TODO make list and imply ordering by horizon?
    std::map<int, ::reasoner::asp::Term*> checkTerms; //TODO make list and imply ordering by horizon?

    bool baseRegistered;
};

} /* namespace wm */



