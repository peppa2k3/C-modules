#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 5
#define MAX_NAME_LENGTH 50
#define MAX_REQUEST_LENGTH 100

// Định nghĩa cấu trúc Nhân viên
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Employee;

// Định nghĩa cấu trúc Request
typedef struct {
    int employee_id;
    char request[MAX_REQUEST_LENGTH];
} Request;

// Hàm để nhập nhân viên
void input_employee(Employee *employee) {
    printf("Nhập ID nhân viên: ");
    scanf("%d", &employee->id);
    getchar(); // Đọc ký tự xuống dòng sau khi nhập ID
    printf("Nhập tên nhân viên: ");
    fgets(employee->name, MAX_NAME_LENGTH, stdin);
    employee->name[strcspn(employee->name, "\n")] = '\0';  // Xóa ký tự xuống dòng nếu có
}

// Hàm để nhập yêu cầu cho nhân viên
void input_request(Request *request) {
    printf("Nhập ID nhân viên để gửi yêu cầu: ");
    scanf("%d", &request->employee_id);
    getchar(); // Đọc ký tự xuống dòng sau khi nhập ID
    printf("Nhập yêu cầu: ");
    fgets(request->request, MAX_REQUEST_LENGTH, stdin);
    request->request[strcspn(request->request, "\n")] = '\0';  // Xóa ký tự xuống dòng nếu có
}

// Hàm để hiển thị danh sách nhân viên
void display_employees(Employee employees[], int count) {
    printf("\nDanh sách nhân viên:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Tên: %s\n", employees[i].id, employees[i].name);
    }
}

// Hàm xử lý yêu cầu từ người dùng
void handle_request(Employee employees[], int count, Request request) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (employees[i].id == request.employee_id) {
            printf("\nYêu cầu của bạn đến nhân viên %s (ID: %d): %s\n", employees[i].name, employees[i].id, request.request);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Không tìm thấy nhân viên với ID %d.\n", request.employee_id);
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    Request request;
    int employee_count = 0;

    printf("Nhập thông tin nhân viên:\n");

    // Nhập danh sách nhân viên
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        printf("\nNhân viên %d:\n", i + 1);
        input_employee(&employees[i]);
        employee_count++;
    }

    display_employees(employees, employee_count);

    // Nhập yêu cầu và xử lý
    printf("\nNhập yêu cầu của bạn:\n");
    input_request(&request);
    handle_request(employees, employee_count, request);

    return 0;
}
