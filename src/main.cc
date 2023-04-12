//
// Created by hwf on 2023/4/7.
//

#include <string>
#include <reader_util/reader_util.h>

void unpackSingleFile(const std::string& path, const std::string& outFolder) {
  reader_util::FileReader reader(path, reader_util::BIG);
  auto metaSize = reader.readUInt32();
  auto fileSize = reader.readUInt32();
  auto version = reader.readUInt32();
  auto dataOffset = reader.readUInt32();
  printf("metaSize: %d, fileSize: %d, version: %d, dataOffset: %d", metaSize, fileSize, version, dataOffset);
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