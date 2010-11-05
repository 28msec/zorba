#ifndef CURL_WRAPPERS_H
#define CURL_WRAPPERS_H

#include <curl/curl.h>
#include <iostream>

#define LOC_INFO  << __FILE__ << ":" << __LINE__ << std::endl

CURL* curl_easy_init_wrapped(const char* file, const int line);

CURLcode curl_easy_setopt_wrapped(const char* file, const int line, CURL* curl, CURLoption option, char* char_args);

CURLcode curl_easy_setopt_wrapped(const char* file, const int line, CURL* curl, CURLoption option, const char* args);
CURLcode curl_easy_setopt_wrapped(const char* file, const int line, CURL* curl, CURLoption option, void* args);
CURLcode curl_easy_setopt_wrapped(const char* file, const int line, CURL* curl, CURLoption option, size_t(*)(char*, size_t, size_t, void*));
CURLcode curl_easy_setopt_wrapped(const char* file, const int line, CURL* curl, CURLoption option, size_t(*)(void*, size_t, size_t, void*));
CURLcode curl_easy_setopt_wrapped(const char* file, const int line, CURL* curl, CURLoption option, int args);

CURLMcode curl_multi_perform_wrapped(const char*file, const int line, CURLM *multi_handle, int *running_handles);
CURLMsg* curl_multi_info_read_wrapped(const char* file, const int line, CURLM *multi_handle, int *msgs_in_queue);
CURLMcode curl_multi_add_handle_wrapped(const char* file, const int line, CURLM *multi_handle, CURL *curl_handle);
CURLMcode curl_multi_remove_handle_wrapped(const char* file, const int line, CURLM *multi_handle, CURL *curl_handle);

void curl_slist_free_all_wrapped(const char* file, const int line, curl_slist *list);
void curl_formfree_wrapped(const char*file, const int line, curl_httppost *form);

curl_slist* curl_slist_append_wrapped(const char* file, const int line, curl_slist *list, const char *value);

#endif // CURL_WRAPPERS_H
