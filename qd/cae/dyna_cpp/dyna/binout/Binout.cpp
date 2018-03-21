
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

#include <dyna_cpp/dyna/binout/Binout.hpp>

extern "C" {
#include <dyna_cpp/dyna/binout/lsda/lsda.h>
#include <dyna_cpp/dyna/binout/lsda/lsda_internal.h>
}

namespace qd {

/**
 * @brief Constructor of a Binout
 * @param string filepath
 */
Binout::Binout(const std::string& _filepath)
  : filepath(_filepath)
{

  this->fhandle = lsda_open((char*)&filepath[0], LSDA_READONLY);
  if (this->fhandle == -1) {
    throw(std::invalid_argument("Error while opening Binout."));
  }
}

/**
 * @brief Destructor of a Binout
 */
Binout::~Binout()
{
  lsda_close(this->fhandle);
}

/** Perform a cd in the binout.
 * @brief Binout::binout_cd
 * @param string _path
 */
void
Binout::cd(const std::string& _path)
{

  if (lsda_cd(this->fhandle, (char*)&_path[0]) == -1)
    throw(std::invalid_argument("Unexpected error during lsda_cd: " + _path));
}

/**
 * @brief Check if a certain variable exists for the path
 * @param _path
 * @return exists
 */
bool
Binout::exists(const std::string& _path)
{
  size_t length;
  int32_t type_id = 0;
  int32_t filenum = 0;
  lsda_queryvar(this->fhandle, (char*)&_path[0], &type_id, &length, &filenum);
  /*
  if (type_id < 0)
    throw(
      std::invalid_argument("Binout.exists encountered an error on: " + _path));
  */
  return type_id >= 0;
}

/** Checks if the entry has children
 *
 * @param _path
 * @return has_children
 */
bool
Binout::has_children(const std::string& _path)
{
  size_t length = 0;
  int32_t type_id = -1;
  int32_t filenum = -1;
  lsda_queryvar(this->fhandle, (char*)&_path[0], &type_id, &length, &filenum);
  if (type_id < 0)
    throw(std::invalid_argument(
      "Binout.has_children encountered an error on: " + _path));

  if (type_id == 0 && length > 0) {
    return true;
  } else {
    return false;
  }
}

/** Checks if the entry has children
 *
 * @param _path
 * @return has_children
 */
bool
Binout::is_variable(const std::string& _path)
{
  size_t length = 0;
  int32_t type_id = -1;
  int32_t filenum = -1;
  lsda_queryvar(this->fhandle, (char*)&_path[0], &type_id, &length, &filenum);
  if (type_id < 0)
    throw(std::invalid_argument(
      "Binout.has_children encountered an error on: " + _path));

  if (type_id > 0 && length > 0) {
    return true;
  } else {
    return false;
  }
}

/** get the labels in a directory in the binout
 * @param _path
 * @return list : list of names
 */
std::vector<std::string>
Binout::get_children(const std::string& _path)
{
  LSDA_Length nChildren = 0; // == size_t
  const int follow = 0;

  char** names = lsda_get_children_names(
    this->fhandle, (char*)&_path[0], follow, &nChildren);

  // bad stuff happened
  if (names == nullptr || nChildren == 0) {
    return std::vector<std::string>();
  }

  // copy
  auto ret = std::vector<std::string>(names, names + nChildren);

  // delete ... I don't like C
  for (LSDA_Length iChild = 0; iChild < nChildren; ++iChild)
    delete[] names[iChild];
  delete[] names;

  // return
  return ret;
}

} // namespace qd
