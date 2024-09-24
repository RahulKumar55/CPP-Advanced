// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\26\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <future>
#include <thread>
#include <functional>
#include "TreasureMap.h"

namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.

            // END TODO

            std::ofstream f(filename, std::ios::out | std::ios::binary | std::ios::trunc);
            if (!f)
            {
                throw std::string(filename) + " cannot be opened";
            }
            f.write(reinterpret_cast<char*>(&rows), sizeof(rows));
            f.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));
            for (size_t i = 0; i < rows; i++)
            {
                f.write((map[i].c_str()), map[i].size());
            }
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.

        // END TODO

        std::ifstream f(filename, std::ios::in | std::ios::binary);
        if (!f)
        {
            throw std::string(filename) + " cannot be opened";
        }
        else
        {
            clear();
            f.read(reinterpret_cast<char*>(&rows), 8);
            f.read(reinterpret_cast<char*>(&colSize), 8);
            map = new std::string[rows]{};
            for (size_t i = 0; i < rows; i++)
            {
                char* c = new char[colSize + 1]{};
                f.read(c, colSize);
                map[i] = c;
                delete[] c;
            }
        }
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        /*for (size_t i = 0; i < rows; ++i){
            count += digForTreasure(map[i], mark);
        }*/

        size_t i1 = rows / 4;
        size_t i2 = (rows / 4) + i1;
        size_t i3 = (rows / 4) + i2;
        size_t i4 =  rows - i3;
        std::string st1{}, st2{}, st3{}, st4{};
        for (size_t i = 0; i < rows; i++)
        {
            if (i <= i1)
            {
                st1.append(map[i]);
            }
            if (i <= i2 && i > i1)
            {
                st2.append(map[i]);
            }
            if (i <= i3 && i > i2)
            {
                st3.append(map[i]);
            }
            if (i <= i4 && i > i3)
            {
                st3.append(map[i]);
            }
        }

        auto f1 = std::bind(digForTreasure, std::placeholders::_1, mark);

        std::packaged_task<size_t(const std::string&)> pt1(f1);
        std::future<size_t> r1 = pt1.get_future();
        std::packaged_task<size_t(const std::string&)> pt2(f1);
        std::future<size_t> r2 = pt2.get_future();
        std::packaged_task<size_t(const std::string&)> pt3(f1);
        std::future<size_t> r3 = pt3.get_future();
        std::packaged_task<size_t(const std::string&)> pt4(f1);
        std::future<size_t> r4 = pt4.get_future();

        std::thread t1(std::move(pt1), std::ref(st1));
        std::thread t2(std::move(pt2), std::ref(st2));
        std::thread t3(std::move(pt3), std::ref(st3));
        std::thread t4(std::move(pt4), std::ref(st4));
        t1.join();
        t2.join();
        t3.join();
        t4.join();

        count = r1.get() + r2.get() + r3.get() + r4.get();
        return count;
    }
}