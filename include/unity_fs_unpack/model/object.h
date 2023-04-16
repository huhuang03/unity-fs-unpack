//
// Created by huhua on 2023/4/15.
//

#ifndef UNITY_FS_UNPACK_INCLUDE_UNITY_FS_UNPACK_MODEL_OBJECT_H_
#define UNITY_FS_UNPACK_INCLUDE_UNITY_FS_UNPACK_MODEL_OBJECT_H_
#include "../core/i_parseable.h"
#include <iostream>

class Object: public IParseable {
 public:
  void parse(reader_util::FileReader &file_reader) override;
  friend std::ostream& operator<<(std::ostream& os, const Object& object);

 private:
  int pathId_;
  int byteStart_;
  int byteSize_;
  int typeId_;
};
#endif //UNITY_FS_UNPACK_INCLUDE_UNITY_FS_UNPACK_MODEL_OBJECT_H_
