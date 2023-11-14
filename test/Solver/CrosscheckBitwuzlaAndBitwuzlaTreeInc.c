// REQUIRES: bitwuzla
// RUN: %clang %s -emit-llvm %O0opt -c -o %t1.bc
// RUN: rm -rf %t.klee-out
// RUN: %klee --output-dir=%t.klee-out --search=bfs --solver-backend=bitwuzla-tree --max-solvers-approx-tree-inc=4 --debug-crosscheck-core-solver=bitwuzla --debug-bitwuzla-validate-models --debug-assignment-validating-solver --use-cex-cache=false --use-guided-search=none %t1.bc 2>&1 | FileCheck %s
// RUN: rm -rf %t.klee-out
// RUN: %klee --output-dir=%t.klee-out --search=dfs --solver-backend=bitwuzla-tree --max-solvers-approx-tree-inc=64 --debug-crosscheck-core-solver=bitwuzla --debug-bitwuzla-validate-models --debug-assignment-validating-solver --use-cex-cache=false --use-guided-search=none %t1.bc 2>&1 | FileCheck %s

#include "ExerciseSolver.c.inc"

// CHECK: KLEE: done: completed paths = 18
// CHECK: KLEE: done: partially completed paths = 0
