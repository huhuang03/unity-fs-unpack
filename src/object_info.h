//
// Created by hwf on 2023/4/13.
//

#ifndef UNITY_FS_UNPACK_SRC_OBJECT_INFO_H_
#define UNITY_FS_UNPACK_SRC_OBJECT_INFO_H_

#include "./core/i_parseable.h"

class ObjectInfo: public IParseable {
 public:
  ObjectInfo(uint32_t globalDataOffset);
 private:
  void parse(reader_util::FileReader &file_reader) override;
 private:
  uint32_t globalDataOffset_;
};

#endif //UNITY_FS_UNPACK_SRC_OBJECT_INFO_H_
