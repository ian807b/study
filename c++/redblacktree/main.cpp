
//
// Created by Ian Hwang on 2022-03-26.
//

#include <iostream>
#include <string>

#include "RedBlackTree.h"

using std::string;

int main() {
  RedBlackTree<string, string> rb1;  // Instantiation

  cout << "=============== BEGIN OF INSERTION ===============" << endl;
  cout << rb1.insert("aaa", " -a") << endl;
  cout << rb1.insert("aaa", " -b") << endl;
  cout << rb1.insert("aaa", " -c") << endl;
  cout << rb1.insert("aaa", " -e") << endl;
  cout << rb1.insert("aaa", " -f") << endl;

  cout << " =========== END OF INSERTION =============" << endl << endl << endl;

  // cout << " =========== BEGIN OF PRINT ==============" << endl;
  // rb1.print();
  // cout << " =========== END OF PRINT =============" << endl << endl << endl;

  // cout << " =========== BEGIN OF SIZE ==============" << endl;
  // cout << "RB1 size = " << rb1.size() << endl;
  // cout << " =========== END OF SIZE =============" << endl << endl << endl;

  // cout << " =========== BEGIN OF PRINT ==============" << endl;
  // cout << rb1.getRoot() << endl;
  // cout << " =========== END OF PRINT =============" << endl << endl << endl;

  // cout << "============= BEGIN OF REMOVAL  ==============" << endl;
  // cout << "Removing... " << rb1.remove(1) << endl << endl;
  // cout << "Removing... " << rb1.remove('b') << endl << endl;
  // cout << "Removing... " << rb1.remove('c') << endl << endl;
  // cout << "Removing... " << rb1.remove('d') << endl << endl;
  // cout << "Removing... " << rb1.remove('e') << endl << endl;
  // cout << "Removing... " << rb1.remove('f') << endl << endl;
  // cout << "Removing... " << rb1.remove('g') << endl << endl;
  // cout << "Removing... " << rb1.remove('h') << endl << endl;
  // cout << "Removing... " << rb1.remove('i') << endl << endl;
  // cout << "Removing... " << rb1.remove('j') << endl << endl;
  // cout << "Removing... " << rb1.remove('k') << endl << endl;
  // cout << "Removing... " << rb1.remove('l') << endl << endl;
  // cout << "Removing... " << rb1.remove('m') << endl << endl;
  // cout << "Removing... " << rb1.remove('n') << endl << endl;
  // cout << "Removing... " << rb1.remove('o') << endl << endl;

  // cout << "============= END OF REMOVAL  ==============" << endl << endl << endl;

  // cout << " =========== BEGIN OF SEARCH ONE ==============" << endl;
  // cout << rb1.search('f') << endl;
  // cout << " =========== END OF SEARCH ONE =============" << endl << endl << endl;

  // cout << " =========== BEGIN OF PRINT ==============" << endl;
  // rb1.print();
  // cout << " =========== END OF PRINT =============" << endl << endl << endl;

  // cout << " =========== BEGIN OF SIZE ==============" << endl;
  // cout << "RB1 size = " << rb1.size() << endl;
  // cout << " =========== END OF SIZE =============" << endl << endl << endl;

  // cout << " =========== BEGIN OF GETROOT ==============" << endl;
  // cout << rb1.getRoot() << endl << endl << endl;
  // cout << " =========== END OF GETROOT =============" << endl << endl << endl;

  // vector<string> v1 = rb1.search('a', 'f');
  // cout << "============= BEGIN OF SEARCH RANGE ==============" << endl;
  // cout << "Printing the vector v1...(search) " << endl;
  // for (int i = 0; i < v1.size(); i++) {
  //   cout << v1[i] << ' ';
  // }
  // cout << endl << " =========== END OF SEARCH RANGE =============" << endl << endl << endl;

  // cout << "============= BEGIN OF VALUES ==============" << endl;
  // vector<string> v2 = rb1.values();
  // cout << "Printing the values vector, v2..." << endl;
  // for (int i = 0; i < v2.size(); i++) {
  //   cout << v2[i] << ' ';
  // }
  // cout << endl << "============= END OF VALUES ==============" << endl << endl << endl;

  // cout << "============= BEGIN OF KEYS ==============" << endl;
  // vector<char> v3 = rb1.keys();
  // cout << "Printing the keys vector, v3..." << endl;
  // for (int i = 0; i < v3.size(); i++) {
  //   cout << v3[i] << ' ';
  // }
  // cout << endl << "============= END OF KEYS ==============" << endl << endl << endl;

  cout << " =========== BEGIN OF Operator ==============" << endl;
  RedBlackTree<string, string> rb2(rb1);
  cout << " =========== END OF Operator =============" << endl << endl << endl;

  cout << "============= BEGIN OF REMOVAL  ==============" << endl;
  cout << "Removing... " << rb2.remove("aaa") << endl << endl;
  cout << "Removing... " << rb2.remove("aaa") << endl << endl;
  cout << "Removing... " << rb2.remove("aaa") << endl << endl;
  cout << "Removing... " << rb2.remove("aaa") << endl << endl;
  // cout << "Removing... " << rb2.remove("bbb") << endl << endl;
  // cout << "Removing... " << rb2.remove("ccc") << endl << endl;
  // cout << "Removing... " << rb2.remove("eee") << endl << endl;
  // cout << "Removing... " << rb2.remove("fff") << endl << endl;
  // cout << "Removing... " << rb2.remove("ggg") << endl << endl;
  // cout << "Removing... " << rb2.remove("hhh") << endl << endl;
  // cout << "Removing... " << rb2.remove("iii") << endl << endl;
  // cout << "Removing... " << rb2.remove("kkk") << endl << endl;
  // cout << "Removing... " << rb2.remove("lll") << endl << endl;
  // cout << "Removing... " << rb2.remove("mmm") << endl << endl;
  cout << "============= END OF REMOVAL  ==============" << endl << endl << endl;

  cout << " =========== BEGIN OF SEARCH ONE ==============" << endl;
  cout << rb2.search("3") << endl;
  cout << " =========== END OF SEARCH ONE =============" << endl << endl << endl;

  cout << " =========== BEGIN OF PRINT ==============" << endl;
  cout << " =========== END OF PRINT =============" << endl << endl << endl;

  cout << " =========== BEGIN OF SIZE ==============" << endl;
  cout << "RB1 size = " << rb2.size() << endl;
  cout << " =========== END OF SIZE =============" << endl << endl << endl;

  cout << " =========== BEGIN OF GETROOT ==============" << endl;
  cout << rb2.getRoot() << endl << endl << endl;
  cout << " =========== END OF GETROOT =============" << endl << endl << endl;

  vector<string> v1 = rb2.search("ooo", "zzz");
  cout << "============= BEGIN OF SEARCH RANGE ==============" << endl;
  cout << "Printing the vector v1...(search) " << endl;
  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << ' ';
  }
  cout << endl << " =========== END OF SEARCH RANGE =============" << endl << endl << endl;

  cout << "============= BEGIN OF VALUES ==============" << endl;
  vector<string> v2 = rb2.values();
  cout << "Printing the values vector, v2..." << endl;
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << ' ';
  }
  cout << endl << "============= END OF VALUES ==============" << endl << endl << endl;

  cout << "============= BEGIN OF KEYS ==============" << endl;
  vector<string> v3 = rb2.keys();
  cout << "Printing the keys vector, v3..." << endl;
  for (int i = 0; i < v3.size(); i++) {
    cout << v3[i] << ' ';
  }
  cout << endl << "============= END OF KEYS ==============" << endl << endl << endl;

  cout << endl << endl << endl << v1.size() << endl;
  cout << endl << endl << endl << v2.size() << endl;
  cout << endl << endl << endl << v3.size() << endl;

  return 0;
}
