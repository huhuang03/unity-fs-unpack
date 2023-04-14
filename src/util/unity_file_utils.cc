//
// Created by hwf on 2023/4/14.
//
#include "./unity_file_utils.h"

std::vector<uint32_t> readUInt32Array(reader_util::FileReader *file_reader) {
  uint32_t len = file_reader->readUInt32();
  std::vector<uint32_t> rst;
  for (int i = 0; i < len; ++i) {
    rst.push_back(file_reader->readUInt32());
  }
  return rst;
}
