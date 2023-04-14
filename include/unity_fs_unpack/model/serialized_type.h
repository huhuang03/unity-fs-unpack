//
// Created by huhua on 2023/4/12.
//

#ifndef UNITY_FS_UNPACK_SRC_MODEL_SERIALIZED_TYPE_H_
#define UNITY_FS_UNPACK_SRC_MODEL_SERIALIZED_TYPE_H_

#include "../../include/unity_fs_unpack/core/i_parseable.h"
#include <iostream>

class SerializedType: public IParseable {
 public:
  explicit SerializedType(int version);
  void parse(reader_util::FileReader &file_reader) override;
  friend std::ostream& operator<<(std::ostream& os, const SerializedType& serialized_type);
 private:
  int version_ = 0;
  int classId_ = 0;
  bool strippedType_ = false;
  uint16_t scriptTypeIndex = 0;
  char scriptId_[16] = {0};
  char oldTypeHash_[16] = {0};
};

#endif //UNITY_FS_UNPACK_SRC_MODEL_SERIALIZED_TYPE_H_
