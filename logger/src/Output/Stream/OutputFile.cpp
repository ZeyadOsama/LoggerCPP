//
// Created by zeyad-osama on 25/07/2020.
//

#include <Output/Stream/OutputFile.h>
#include <Utils/Timestamp.h>
#include <Utils/Utils.h>
#include <Utils/LibVars/Extension.h>

#include <dirent.h>
#include <algorithm>

#define MAX_FILES 10

using namespace std;

namespace Log {

    std::string GenerateFileName() {
        Timestamp t;
        t.Generate();
        char buffer[24];
        sprintf(buffer, "%.4u-%.2u-%.2u %.2u:%.2u:%.2u.%.3u",
                t.year, t.month, t.day, t.hour, t.minute, t.second, t.ms);
        printf("%s\n", buffer);
        return std::string(buffer) + LOG_EXTENSION;
    }

    OutputFile::OutputFile(const Configuration::Pointer &apConfiguration) :
            mFile(nullptr) {
        mFileName = apConfiguration->Get("filename", GenerateFileName().c_str());
        Open();
    }

    OutputFile::~OutputFile() {
        Close();
    }

    void OutputFile::Open() const {
        mFile = fopen(CAT_STR_TO_CHR(LOG_OUT_DIR, mFileName), "ab");
    }

    void OutputFile::Close() const {
        if (mFile != nullptr) {
            fclose(mFile);
            mFile = nullptr;
        }
    }

    void OutputFile::Out(const Channel::Pointer &apChannel, const Log &apLog) const {
        const Timestamp &t = apLog.GetTimestamp();
        if (mFile != nullptr) {
            fprintf(mFile, "%.4u-%.2u-%.2u %.2u:%.2u:%.2u.%.3u  %-12s %s %s\n",
                    t.year, t.month, t.day, t.hour, t.minute, t.second, t.ms,
                    apChannel->GetName(),
                    to_string(apLog.GetLevel()),
                    (apLog.GetStream()).str().c_str());
            fflush(mFile);
        }
    }

    void OutputFile::Terminate() const {
        vector<string> files;
        struct dirent *entry;
        DIR *dp = opendir(string(LOG_OUT_DIR).c_str());
        if (dp != nullptr)
            while ((entry = readdir(dp))) {
                string file_name = entry->d_name;
                if (file_name.find(LOG_EXTENSION) != string::npos) {
                    files.push_back(file_name);
                }
            }
        sort(files.begin(), files.end());
        if (files.size() > MAX_FILES) {
            for (int i = 0; i < files.size() - MAX_FILES; ++i) {
                remove(CAT_STR_TO_CHR(LOG_OUT_DIR, files[i]));
            }
        }
    }
}