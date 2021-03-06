#pragma once

#include <vector>

#include <nv_storage.hpp>

#define TOTP_MAX_IDX        0x7f
#define BITS_PER_BASE32_CHAR      5     // Base32 expands space by 8/5

typedef struct {
    std::string title;
    std::vector<uint8_t> token;
} totp_tuple_t;

typedef std::vector<totp_tuple_t> totp_tuple_list;

class totp_model
{
    public:
        totp_model();
        ~totp_model();
        esp_err_t add_totp_tuple(const std::string &title, const std::string &token);
        esp_err_t remove_totp_tuple(const std::string &title);
        totp_tuple_t get_totp_tuple(const std::string &title);
        totp_tuple_list get_totp_list();
        void refresh_list();
        void save_list();

    private:
        nv_storage nvs;
        totp_tuple_list totp_list{};

};