//
// Created by huhua on 2023/4/12.
//

#ifndef UNITY_FS_UNPACK_SRC_I_UNITY_FILE_H_
#define UNITY_FS_UNPACK_SRC_I_UNITY_FILE_H_

class IUnityFile {
 public:
  virtual int getEndian() = 0;
  // bad name object?
  virtual int getObjectCount() = 0;
};

#endif //UNITY_FS_UNPACK_SRC_I_UNITY_FILE_H_
