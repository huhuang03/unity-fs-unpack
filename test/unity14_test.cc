//
// Created by hwf on 2023/4/13.
//

#include <gtest/gtest.h>
#include <boost/filesystem.hpp>
#include <unity_fs_unpack/unity_fs_unpack.h>
#include <reader_util/reader_util.h>

namespace fs = boost::filesystem;

TEST(test14, BasicAssertions) {
  auto filePath = fs::current_path() / fs::path("../../test/unity14_file");
  ASSERT_TRUE(fs::exists(filePath));
  reader_util::FileReader fileReader(filePath.string(), reader_util::BIG);
  UnityFile unityFile(&fileReader);
  ASSERT_EQ(unityFile.getUnityVersion(), "2018.4.30f1");
  ASSERT_EQ(unityFile.getTargetPlatform(), Android);
  ASSERT_EQ(unityFile.getVersion(), 17);
  printf("version: %d\n", unityFile.getVersion());
  printf("objectCount: %d", unityFile.getObjectCount());
//  printf("objectCount: %d", unityFile.getObjectCount());
}