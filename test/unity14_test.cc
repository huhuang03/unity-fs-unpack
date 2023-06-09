//
// Created by hwf on 2023/4/13.
//

#include <gtest/gtest.h>
#include <boost/filesystem.hpp>
#include <unity_fs_unpack/unity_fs_unpack.h>
#include <reader_util/reader_util.h>
#include <iostream>

namespace fs = boost::filesystem;

TEST(test14, BasicAssertions) {
  auto filePath = fs::current_path() / fs::path("../../test/unity14_file");
  ASSERT_TRUE(fs::exists(filePath));
  reader_util::FileReader fileReader(filePath.string(), reader_util::BIG);
  UnityFile unityFile(&fileReader);
  ASSERT_EQ(unityFile.getUnityVersion(), "2018.4.30f1");
  ASSERT_EQ(unityFile.getTargetPlatform(), Android);
  ASSERT_EQ(unityFile.getVersion(), 17);
  ASSERT_EQ(unityFile.getObjectCount(), 1);
//  auto types = unityFile.getSerializedTypes();
//
//  for (auto it = types.begin(); it != types.end(); ++it) {
//    std::cout << *it << " ";
//  }

  for (const auto &item : unityFile.objects()) {
    std::cout << item << std::endl;
  }

//  auto objects = unityFile.
//  std::cout << "type: " << types << std::endl;
//  printf("typeCount: %d\n", unityFile.getTypeCount());
//  printf("version: %d\n", unityFile.getVersion());
  printf("objectCount: %d\n", unityFile.getObjectCount());
//  printf("enableTypeTree: %d", unityFile.isEnableTypeTree());
}