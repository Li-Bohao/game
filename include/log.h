#ifndef LOG_H
#define LOG_H
#include <string>
#include <fstream>
#include <mutex>
#include <chrono>
#include <format>
constexpr const char *log_file_name = "LOG.txt";
class Log
{
private:
	std::mutex m_mutex;
	std::string get_time()
	{
		auto now = std::chrono::system_clock::now();
		auto local_time = std::chrono::zoned_time{std::chrono::current_zone(), now};
		return std::format("{:%Y-%m-%d %H:%M:%S}", local_time);
	}
	std::ofstream &get_file()
	{
		static std::ofstream log_file(log_file_name, std::ios::app);
		return log_file;
	}
	void record(std::string_view level, std::string_view content)
	{
		std::lock_guard(m_mutex);
		get_file() << get_time() << ' ' << level << ": " << content << std::endl;
	}

public:
	void Error(std::string_view content)
	{
		record("Error", content);
	}
	void Notice(std::string_view content)
	{
		record("Notice", content);
	}
};
#endif