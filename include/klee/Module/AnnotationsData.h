#ifndef KLEE_ANNOTATIONS_DATA_H
#define KLEE_ANNOTATIONS_DATA_H

#include "klee/Module/Annotation.h"
#include "klee/Module/TaintAnnotation.h"

namespace klee {

struct AnnotationsData final {
  AnnotationsMap annotations;
  TaintAnnotation taintAnnotation;

  explicit AnnotationsData(const std::string &annotationsFile,
                           const std::string &taintAnnotationsFile);
  virtual ~AnnotationsData();
};

} // namespace klee

#endif // KLEE_ANNOTATIONS_DATA_H
