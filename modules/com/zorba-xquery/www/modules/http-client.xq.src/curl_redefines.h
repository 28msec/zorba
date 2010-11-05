#ifndef CURL_REDEFINES_H
#define CURL_REDEFINES_H

#define curl_easy_init() curl_easy_init_wrapped(__FILE__, __LINE__)
#define curl_multi_init() curl_multi_init_wrapped(__FILE__, __LINE__)
#define curl_easy_setopt(x, y, z) curl_easy_setopt_wrapped(__FILE__, __LINE__, x, y, z)
//#define curl_multi_perform(x,y) curl_multi_perform_wrapped(__FILE__, __LINE__, x, y)
//#define curl_multi_info_read(x,y) curl_multi_info_read_wrapped(__FILE__, __LINE__, x, y)
#define curl_slist_free_all(x) curl_slist_free_all_wrapped(__FILE__, __LINE__, x)
#define curl_formfree(x) curl_formfree_wrapped(__FILE__, __LINE__, x)
#define curl_slist_append(x,y) curl_slist_append_wrapped(__FILE__, __LINE__, x, y)
#define curl_multi_add_handle(x,y) curl_multi_add_handle_wrapped(__FILE__, __LINE__, x, y)

#endif // CURL_REDEFINES_H
