/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-13 13:35:12
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-13 14:44:51
 * @Description: This file defines some operations for JSON files.
 */

#ifndef _JSON_OPERATION_H_
#define _JSON_OPERATION_H_

#include"link_list.h"

 /// @brief This function reads in all content of a JSON file.
 /// @param file_path file location
 /// @return the content of the file
char * read_json_file(const char * file_path);

/// @brief This functin reads JSON data to make event.
void read_event_from_json_file(LinkList * plist);

#endif // !_JSON_OPERATION_H_