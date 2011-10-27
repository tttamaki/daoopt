/*
 * Main.h
 *
 *  Created on: Oct 18, 2011
 *      Author: lars
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "_base.h"

#include "Problem.h"
#include "Function.h"
#include "Graph.h"
#include "Pseudotree.h"
#include "ProgramOptions.h"
#include "MiniBucketElim.h"

#ifdef PARALLEL_DYNAMIC
  #include "BranchAndBoundMaster.h"
  #include "BoundPropagatorMaster.h"
  #include "SubproblemHandler.h"
  #include "SigHandler.h"
#else
  #ifdef PARALLEL_STATIC
    #include "ParallelManager.h"
  #endif
  #include "BranchAndBound.h"
  #include "BoundPropagator.h"
#endif

#include "BestFirst.h"
#include "LimitedDiscrepancy.h"

class Main {
protected:
  bool m_solved;
  scoped_ptr<ProgramOptions> m_options;
  scoped_ptr<Problem> m_problem;
  scoped_ptr<Pseudotree> m_pseudotree;
  scoped_ptr<Heuristic> m_heuristic;

#if defined PARALLEL_DYNAMIC
  scoped_ptr<BranchAndBoundMaster> m_search;
  scoped_ptr<SearchSpaceMaster> m_space;
#elif defined PARALLEL_STATIC
  scoped_ptr<ParallelManager> m_search;
  scoped_ptr<SearchSpace> m_space;
#else
  scoped_ptr<Search> m_search;
  scoped_ptr<SearchSpace> m_space;
#endif

protected:
  bool runSearchDynamic();
  bool runSearchStatic();
  bool runSearchWorker();

public:
  bool start() const;
  bool parseOptions(int argc, char** argv);
  bool outputInfo() const;
  bool loadProblem();
  bool findOrLoadOrdering();
  bool initSearchSpace();
  bool compileHeuristic();
  bool runLDS();
  bool finishPreproc();
  bool runSearch();
  bool outputStats() const;

  bool isSolved() const { return m_solved; }

  Main();

};

/* Inline implementations */

inline Main::Main() : m_solved(false) {
  /* nothing here */
}

inline bool Main::runSearch() {
  if (m_options->nosearch)
    return false;
  if (m_solved)
    return true;
  cout << "--- Starting search ---" << endl;

#if defined PARALLEL_DYNAMIC
  return runSearchDynamic();
#elif defined PARALLEL_STATIC
  return runSearchStatic();
#else
  return runSearchWorker();
#endif
}


#endif /* MAIN_H_ */