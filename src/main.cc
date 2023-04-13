//
// Created by hwf on 2023/4/7.
//

#include <string>
#include <reader_util/reader_util.h>
#include "../include/unity_fs_unpack/unity_file.h"

void unpackSingleFile(const std::string& path, const std::string& outFolder) {
  reader_util::FileReader reader(path, reader_util::BIG);
  UnityFile unity_file(&reader);
  printf("unity version: %s\n", unity_file.getUnityVersion().c_str());
  printf("typeCount: %d", unity_file.getTypeCount());
}

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Usage: %s file_or_folder dist", argv[0]);
    return -1;
  }

  const char* src = argv[1];
  const char* out = argv[2];
  unpackSingleFile(src, out);
}