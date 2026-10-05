#include <stdio.h>
#include <string.h>

int main() {
    #define MAX_PHIEU 50
    char maPhieu[MAX_PHIEU][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};
    int soLuong = 3;
    int choice;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = ngayQuaHan[i] * 5000;
                    printf("%-3d | %-8s | %-15d | %d VNĐ\n", i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }
                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }
            case 2: {
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                    break;
                }
                printf("Nhap ma phieu muon moi: ");
                scanf("%19s", maPhieu[soLuong]);
                while (getchar() != '\n');

                ngayQuaHan[soLuong] = 0;
                soLuong++;
                printf("Them moi thanh cong!\n");
                break;
            }
            case 3: {
                char searchCode[20];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", searchCode);
                while (getchar() != '\n');

                int foundIndex = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], searchCode) == 0) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maPhieu[foundIndex], foundIndex);
                    int newDays;
                    do {
                        printf("Nhap so ngay qua han moi: ");
                        if (scanf("%d", &newDays) != 1) {
                            while (getchar() != '\n');
                            newDays = -1;
                        }
                        while (getchar() != '\n');

                        if (newDays < 0) {
                            printf("Loi: So ngay qua han phai la so nguyen khong am (>= 0). Vui long nhap lai!\n");
                        }
                    } while (newDays < 0);

                    ngayQuaHan[foundIndex] = newDays;
                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", maPhieu[foundIndex], newDays);
                } else {
                    printf("Khong tim thay ma phieu muon '%s' trong he thong!\n", searchCode);
                }
                break;
            }
            case 0:
                printf("Cam ơn ban da su dung he thong LIBRARY_WMS. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai tu 0 den 3.\n");
        }
    } while (choice != 0);

    return 0;
}