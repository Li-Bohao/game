#pragma once
#include<string>
#include<fstream>
#include<mutex>
constexpr const char* log_file_name = "LOG.txt";
class Log {
private:
	std::mutex m_mutex;
	std::string get_time();
	std::ofstream& get_file();
	void record(std::string_view level, std::string_view content);
public:
	void Error(std::string_view content);
	void Notice(std::string_view content);
};