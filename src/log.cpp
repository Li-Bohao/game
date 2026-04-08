#include<chrono>
#include<string>
#include<format>
#include<fstream>
#include"log.h"
std::string Log::get_time() {
    auto now = std::chrono::system_clock::now();
    auto local_time = std::chrono::zoned_time{std::chrono::current_zone(), now};
    return std::format("{:%Y-%m-%d %H:%M:%S}", local_time);
}
std::ofstream& Log::get_file() {
    static std::ofstream log_file(log_file_name, std::ios::app);
    return log_file;
}
void Log::record(std::string_view level, std::string_view content) {
    std::lock_guard(m_mutex);
    get_file() << get_time() << ' ' << level << ": " << content << std::endl;
}
void Log::Error(std::string_view content) {
    record("Error", content);
}
void Log::Notice(std::string_view content) {
    record("Notice", content);
}