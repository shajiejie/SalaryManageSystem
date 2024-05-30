//
// Created by 沙杰杰 on 2024/5/30.
//

#ifndef SALARYMANAGESYSTEM_RECORD_MANAGE_H
#define SALARYMANAGESYSTEM_RECORD_MANAGE_H

int getLastRecordRow();

void clearCells(int startRow, int endRow, int startCol, int endCol);

std::vector<readrecord> readAllRecords();

void deleteAndRewriteRecords(int recordToDelete);

void record_change();
#endif //SALARYMANAGESYSTEM_RECORD_MANAGE_H
