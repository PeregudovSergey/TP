//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <fstream>

TEST_F(TreeTestCase, path_does_not_exist) {
  ASSERT_THROW(GetTree("abrakadabra", true), std::invalid_argument); 
}

TEST_F(TreeTestCase, path_exist_but_it_is_not_directory) {
  path path{ "~/abrakadabra" };   
  path /= "kek.txt";
  std::filesystem::create_directories(path.parent_path());
  std::ofstream ofs(path);
  ofs << "here\n"; 
  ofs.close(); 
  ASSERT_THROW(GetTree("~/abrakadabra/kek.txt", true), std::invalid_argument); 
}

TEST_F(TreeTestCase, get_tree_main) {     
  path path{ "~/abrakadabra/kek.txt" };     
  std::filesystem::create_directories(path.parent_path());
  std::ofstream ofs(path);
  ofs << "here\n"; 
  ofs.close();   
  std::filesystem::create_directories("~/abrakadabra/empty_dir");
  FileNode p2 = {"kek.txt", 0, {}}; 
  FileNode p3 = {"empty_dir", 1, {}};
  FileNode p1 = {"~", 1, {p2, p3}};
  GetTree("~", false); 
  GetTree("~", true); 
}

TEST_F(TreeTestCase, operator_eq) {  
  FileNode p1 = {"abc", 0, {}};
  FileNode p2 = {"abc", 0, {}};

  EXPECT_TRUE(p1 == p2); 
}

TEST_F(TreeTestCase, empty_nodes) {     
  path path{ "~/abrakadabra/kek.txt" };     
  std::filesystem::create_directories(path.parent_path());
  std::ofstream ofs(path);
  ofs << "here\n"; 
  ofs.close();   
  std::filesystem::create_directories("~/abrakadabra/empty_dir");
  FileNode p2 = {"kek.txt", 0, {}}; 
  FileNode p3 = {"empty_dir", 1, {}};
  FileNode p1 = {"~", 1, {p2, p3}};
  FilterEmptyNodes(p1, "~");
}

/*
TEST_F(AddTestCase, Month) {
  ASSERT_EQ(GetMonthDays(400, 2), 29);
  ASSERT_EQ(GetMonthDays(1, 2), 28);
  ASSERT_THROW(GetMonthDays(10, -11), std::invalid_argument);  
  ASSERT_EQ(GetMonthDays(11, 4), 30);  
  ASSERT_EQ(GetMonthDays(11, 3), 31);  
}
*/