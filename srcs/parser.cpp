//
// Created by student on 02/05/18.
//

#include <regex>
#include <fstream>
#include <iostream>
#include <log.hpp>
#include "parser.hpp"

Plazza::Parser::Parser()
{
	this->info["PHONE_NUMBER"] = Plazza::Parser::Information::PHONE_NUMBER;
	this->info["EMAIL_ADDRESS"] = Plazza::Parser::Information::EMAIL_ADDRESS;
	this->info["IP_ADDRESS"] = Plazza::Parser::Information::IP_ADDRESS;
}

Plazza::Parser::~Parser()
{}

void Plazza::Parser::phoneParse(const std::string &file_name)
{
	Plazza::log log("output.txt");
	std::ifstream file(file_name);
	std::regex pattern(R"((\d{10})|((\d{2} ){4}\d{2}))");
	std::smatch matches;

	//std::cout << this->id << "Phone_file: " << file_name << std::endl;
	if (file.is_open()) {
		std::string line;
		while (getline (file,line)) {
			if (std::regex_search(line, matches, pattern)) {
				std::string tmp = matches[0];
				//std::cout << "PHONE WINNING:" << tmp << std::endl;
				std::cout << tmp << std::endl;
				log.writeLog("File:\"" + file_name + R"(", type:"PHONE_NUMBER", data:")" + tmp + "\";");
				/*com.sendReply(
						{file_name, Plazza::Information::PHONE_NUMBER, tmp},
						this->fd_write);*/
			}
		}
		//std::cout << this->id << "PHONE not found." << std::endl;
		file.close();
	} //else
		//std::cerr << this->id << "phone open fail." << std::endl;
	//com.sendReply({file_name, Plazza::Information::PHONE_NUMBER, ""}, this->fd_write);
	log.writeLog("File:\"" + file_name + R"(", type:"PHONE_NUMBER", data:"";)");
}

void Plazza::Parser::ipParse(const std::string &file_name)
{
	Plazza::log log("output.txt");
	std::ifstream file(file_name);
	std::regex pattern(R"((\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}))");
	std::smatch matches;

	//std::cout << this->id << "Ip_file: " << file_name << std::endl;
	if (file.is_open()) {
		std::string line;
		while (getline (file,line)) {
			if (std::regex_search(line, matches, pattern)) {
				std::string tmp = matches[0];
				//std::cout << "IP WINNING:" << tmp << std::endl;
				std::cout << tmp << std::endl;
				log.writeLog("File:\"" + file_name + R"(", type:"IP_ADDRESS", data:")" + tmp + "\";");
				//std::cout << this->id << "IP WINNING:" << tmp << std::endl;
			/*	com.sendReply(
						{file_name, Plazza::Information::IP_ADDRESS, tmp},
						this->fd_write);*/
			}
		}
		//std::cout << this->id << "IP not found." << std::endl;
		file.close();
	} //else
	//std::cerr << this->id << "ip open fail." << std::endl;
	//com.sendReply({file_name, Plazza::Information::IP_ADDRESS, ""}, this->fd_write);
	log.writeLog("File:\"" + file_name + R"(", type:"IP_ADDRESS", data:"";)");
}

void Plazza::Parser::emailParse(const std::string &file_name)
{
	Plazza::log log("output.txt");
	std::ifstream file(file_name);
	std::regex pattern("[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+");
	std::smatch matches;

	//std::cout << "Email_file: " << file_name << std::endl;
	if (file.is_open()) {
		std::string line;
		while (getline (file,line)) {
			if (std::regex_search(line, matches, pattern)) {
				std::string tmp = matches[0];
				//std::cout << "EMAIL WINNING:" << tmp << std::endl;
				std::cout << tmp << std::endl;
				log.writeLog("File:\"" + file_name + R"(", type:"EMAIL_ADDRESS", data:")" + tmp + "\";");
				//std::cout << this->id << "Email WINNING:" << tmp << std::endl;
				/*com.sendReply(
						{file_name, Plazza::Information::EMAIL_ADDRESS, tmp},
						this->fd_write);*/
			}
		}
		//std::cout << "email not found." << std::endl;
		file.close();
	} //else
	//std::cerr << this->id << "Email open fail." << std::endl;
	//com.sendReply({file_name, Plazza::Information::EMAIL_ADDRESS, ""}, this->fd_write);
	log.writeLog("File:\"" + file_name + R"(", type:"EMAIL_ADDRESS", data:"";)");
}
