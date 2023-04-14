//
// Created by hwf on 2023/4/14.
//

#ifndef UNITY_FS_UNPACK_INCLUDE_UNITY_FS_UNPACK_MODEL_UNITY_TYPE_H_
#define UNITY_FS_UNPACK_INCLUDE_UNITY_FS_UNPACK_MODEL_UNITY_TYPE_H_
#include <cstdint>
#include <string>

class UnityType {
 private:
  int32_t classId_ = 0;
  bool strippedType;
  int16_t scriptTypeIndex_;
  // TODO typeTree
  char scriptId_[16]; // hash128
  char oldTypeHash_[16]; // hash128
};
#endif //UNITY_FS_UNPACK_INCLUDE_UNITY_FS_UNPACK_MODEL_UNITY_TYPE_H_
