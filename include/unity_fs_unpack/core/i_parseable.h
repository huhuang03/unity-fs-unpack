//
// Created by huhua on 2023/4/12.
//

#ifndef UNITY_FS_UNPACK_SRC_CORE_I_PARSEABLE_H_
#define UNITY_FS_UNPACK_SRC_CORE_I_PARSEABLE_H_
#include "reader_util/reader_util.h"

class IParseable {
  virtual void parse(reader_util::FileReader &file_reader) = 0;
};
#endif //UNITY_FS_UNPACK_SRC_CORE_I_PARSEABLE_H_
