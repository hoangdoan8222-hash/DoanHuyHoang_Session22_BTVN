#include <stdio.h>
#include <string.h>

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct DonHang {
    char maDon[20];
    char tenKH[50];
    struct Ngay ngayDat;
    float tongTien;
    char trangThai[20];  
};

void hienThi(const struct DonHang *dh) {
    printf("Ma don: %s | Khach hang: %s | Ngay dat: %02d/%02d/%d | Tong tien: %.2f | Trang thai: %s\n",
           dh->maDon, dh->tenKH,
           dh->ngayDat.ngay, dh->ngayDat.thang, dh->ngayDat.nam,
           dh->tongTien, dh->trangThai);
}

int main() {
    struct DonHang ds[100];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENU QUAN LY DON HANG =====\n");
        printf("1. Nhap thong tin don hang\n");
        printf("2. Hien thi tat ca don hang\n");
        printf("3. Cap nhat trang thai don hang\n");
        printf("4. Xoa don hang theo ma\n");
        printf("5. Sap xep don hang theo tong tien\n");
        printf("6. Tim don hang theo ma don\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nhap so luong don hang muon them: ");
            {
                int n, i;
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("\nDon hang %d:\n", count + 1);

                    printf("Ma don: ");
                    scanf("%s", ds[count].maDon);

                    printf("Ten khach hang: ");
                    scanf("%s", ds[count].tenKH);

                    printf("Ngay dat (ngay thang nam): ");
                    scanf("%d %d %d",
                          &ds[count].ngayDat.ngay,
                          &ds[count].ngayDat.thang,
                          &ds[count].ngayDat.nam);

                    printf("Tong tien: ");
                    scanf("%f", &ds[count].tongTien);

                    printf("Trang thai (DangXuLy / DaGiao / Huy): ");
                    scanf("%s", ds[count].trangThai);

                    count++;
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("Chua co don hang!\n");
            } else {
                int i;
                printf("\n--- DANH SACH DON HANG ---\n");
                for (i = 0; i < count; i++) {
                    hienThi(&ds[i]);
                }
            }
        }
        else if (choice == 3) {
            char ma[20];
            int found = 0;
            printf("Nhap ma don hang can cap nhat: ");
            scanf("%s", ma);

            {
                int i;
                for (i = 0; i < count; i++) {
                    if (strcmp(ds[i].maDon, ma) == 0) {
                        printf("Nhap trang thai moi (DangXuLy / DaGiao / Huy): ");
                        scanf("%s", ds[i].trangThai);
                        printf("Cap nhat thanh cong!\n");
                        found = 1;
                        break;
                    }
                }
            }
            if (!found) printf("Khong tim thay don hang!\n");
        }
        else if (choice == 4) {
            char ma[20];
            int found = 0;
            printf("Nhap ma don hang muon xoa: ");
            scanf("%s", ma);

            {
                int i;
                for (i = 0; i < count; i++) {
                    if (strcmp(ds[i].maDon, ma) == 0) {
                        int j;
                        for (j = i; j < count - 1; j++) {
                            ds[j] = ds[j + 1];
                        }
                        count--;
                        found = 1;
                        printf("Xoa thanh cong!\n");
                        break;
                    }
                }
            }
            if (!found) printf("Khong tim thay don hang!\n");
        }
        else if (choice == 5) {
            int i, j;
            for (i = 0; i < count - 1; i++) {
                for (j = i + 1; j < count; j++) {
                    if (ds[i].tongTien > ds[j].tongTien) {
                        struct DonHang temp = ds[i];
                        ds[i] = ds[j];
                        ds[j] = temp;
                    }
                }
            }
            printf("Sap xep tang dan theo tong tien thanh cong!\n");
        }
        else if (choice == 6) {
            char ma[20];
            int found = 0;
            printf("Nhap ma don hang can tim: ");
            scanf("%s", ma);

            {
                int i;
                for (i = 0; i < count; i++) {
                    if (strcmp(ds[i].maDon, ma) == 0) {
                        printf("Tim thay don hang:\n");
                        hienThi(&ds[i]);
                        found = 1;
                        break;
                    }
                }
            }
            if (!found) printf("Khong tim thay don hang!\n");
        }

    } while (choice != 0);

    return 0;
}

