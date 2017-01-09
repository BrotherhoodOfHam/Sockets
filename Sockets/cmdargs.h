/*
	Commandline argument parser header
*/

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class CommandLineArgs
{
private:
		
	std::string m_commandLine;
	std::unordered_map<std::string, std::string> m_argPairs;
		
public:
		
	CommandLineArgs() {}
	CommandLineArgs(const std::string& cmdline) { parse(cmdline); }
	~CommandLineArgs() {}
		
	CommandLineArgs(char** argv, int argc)
	{
		std::string cmdline;
		for (int i = 1; i < argc; i++)
		{
			cmdline += argv[i];
			cmdline += " ";
		}

		parse(cmdline);
	}
		
	void parse(const std::string& cmdline);
		
	bool isArgumentTag(const std::string& tag) const
	{
		return (m_argPairs.find(tag) != m_argPairs.end());
	}
		
	std::string getArgumentValue(const std::string& tag) const
	{
		auto it = m_argPairs.find(tag);
			
		if (it == m_argPairs.end())
			return "";
			
		return it->second;
	}

	size_t getArgumentCount() const
	{
		return m_argPairs.size();
	}
};
