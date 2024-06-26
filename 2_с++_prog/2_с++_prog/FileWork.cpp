#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Document.h"
#include "Letter.h"
#include "Menu.h"



bool FileIsEmpty(std::string filename) {
    std::ifstream file;
    file.open(filename);
    char end_of_file;
    if (file.is_open()) {
        file >> end_of_file;
        file.close();
        if (end_of_file < 0) return true;
        else return false;
    }
    return false;

}



bool OpenFile(std::string filename, std::ofstream& file) { // ������ 

    // ���������� ������� ����
    file.open(filename, std::ios::out);// ��� ������ ������ ���������
    if (file.is_open()) {
        //std::cout << "File successfully opened" << "\n";
        return true;
    }
    else {
        std::cout << "Failed to open the file." << "\n";
        return false;
    }
}

uint16_t OpenFile(std::string filename, std::ifstream& file) { //������
    bool is_empty = FileIsEmpty(filename);
    // ���������� ������� ����
    file.open(filename);
    if (file.is_open() && is_empty) {
       // std::cout << "File is not empty, failed to open the file. " << "\n";
        return file_open_empty;
    }
    if (file.is_open()) {
        //std::cout << "File successfully opened" << "\n";
        return file_open;
    }
    else {
        std::cout << "Failed to open the file." << "\n";
        return false;
    }
}




void FileInput(std::unordered_map <std::string, Document*>& document_list) {
    std::ofstream file;

    while (true) {

        //std::cout << "please tape any filenameway" << "\n";
        std::string filename  = "./test.txt";
        //std::cin >> filename;

        //�������� �����:
        if (OpenFile(filename, file)) {
            break;
        }

    }
    // ������ ������ � ����
    file << document_list.size() << "\n";
    for (auto& [name,document] : document_list) {
        file << document->GetType() << " " << document->GetName() <<  " " << document->GetDocumentFilename() << " " << dynamic_cast<Letter*>(document)->GetAddressee() << " " << dynamic_cast<Letter*>(document)->GetSender() << " \n";
            
    }


    //std::cout << "Data successfully written to the file." << std::endl;


    // �������� �����
    file.close();
}


void FileFilling(std::unordered_map <std::string,Document*> &document_list, size_t& size_of_book) {
    std::ifstream file;
    uint16_t file_is_open =0;

    while (true) {

        std::string filename = "./test.txt";
        //std::cout << "please tape any filenameway" << "\n";
        //std::cin >> filename;

        //�������� �����:
        file_is_open = OpenFile(filename, file);
        if (file_is_open) {
            break;
        }

    }
    if (file_is_open == file_open_empty) {
        size_of_book = 0;
    }
    else file >> size_of_book;
    

    // ������ ������ �� �����
    for (int i = 0; i < size_of_book; i++) { // ����������

        std::string type;
        std::string name;
        std::string document_filename;


        file >> type;
        file >> name;
        file >> document_filename;
        file.ignore(); // clear input buffer
        //������� ����� ��� ������ ����� 

        if (type == "letter") {
            auto* document = new Letter;
            std::string addressee; //����������
            std::string sender;
            file >> addressee;
            file >> sender;
            document->SetSender(sender);
            document->SetAddressee(addressee);
            document->SetDocumentFilename(document_filename);
            document->SetName(name);
            document->SetType(type);
            document_list.insert({ name, document });
        }


    }



    // �������� �����
    file.close();
}

void FileFilling(std::unordered_map <std::string, Document*>& document_list, size_t& size_of_book, std::string current_filename) {                    // ��� ������
    std::ifstream file;
    uint16_t file_is_open = 0;

    while (true) {

        std::string filename = current_filename;
        //std::cout << "please tape any filenameway" << "\n";
        //std::cin >> filename;

        //�������� �����:
        file_is_open = OpenFile(filename, file);
        if (file_is_open) {
            break;
        }

    }
    if (file_is_open == file_open_empty) {
        size_of_book = 0;
    }
    else file >> size_of_book;
    // ������ ������ �� �����
    // ������ ������ �� �����
    for (int i = 0; i < size_of_book; i++) { // ����������

        std::string type;
        std::string name;
        std::string document_filename;


        file >> type;
        file >> name;
        file >> document_filename;
        file.ignore(); // clear input buffer
        //������� ����� ��� ������ ����� 

        if (type == "letter") {
            auto* document = new Letter;
            std::string addressee; //����������
            std::string sender;
            file >> addressee;
            file >> sender;
            document->SetSender(sender);
            document->SetAddressee(addressee);
            document->SetDocumentFilename(document_filename);
            document->SetName(name);
            document->SetType(type);
            document_list.insert({ name, document });
        }


    }


    // �������� �����
    file.close();
}



