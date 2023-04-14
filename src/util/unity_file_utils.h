//
// Created by hwf on 2023/4/14.
//

#ifndef UNITY_FS_UNPACK_SRC_UTIL_UNITY_FILE_UTILS_H_
#define UNITY_FS_UNPACK_SRC_UTIL_UNITY_FILE_UTILS_H_
#include <vector>
#include <reader_util/reader_util.h>

std::vector<uint32_t> readUInt32Array(reader_util::FileReader *file_reader);
#endif //UNITY_FS_UNPACK_SRC_UTIL_UNITY_FILE_UTILS_H_
