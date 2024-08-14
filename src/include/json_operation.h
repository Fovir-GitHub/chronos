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

/// @brief This function should be run before quiting the program.
/// @param plist the link list stores data
/// @param file_path the output file path
void before_quit(LinkList * plist, const char * file_path);

/// @brief This function turns Event structure to json file form.
/// @param event the source Event
/// @return a cJSON object
cJSON * make_json_from_event(const Event * event);

/// @brief Print the result to the JSON file.
/// @param file_path the output path
/// @param json the JSON file content
void output_to_json_file(const char * file_path, cJSON * json);

#endif // !_JSON_OPERATION_H_