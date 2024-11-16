# G2FA Secret Extractor

**G2FA Secret Extractor** là một công cụ mã nguồn mở được viết bằng ngôn ngữ C, dùng để trích xuất và giải mã các secret key từ liên kết `otpauth-migration` của Google Authenticator. Công cụ này hỗ trợ giải mã URL-encoded, base64, và phân tích cú pháp dữ liệu protobuf, sau đó mã hóa secret key sang định dạng base32 để hiển thị cho người dùng.

## 📋 Mục lục

- [Giới thiệu](#-giới-thiệu)
- [Yêu cầu](#️-yêu-cầu)
- [Cài đặt](#-cài-đặt)
- [Hướng dẫn sử dụng](#-hướng-dẫn-sử-dụng)
- [Ví dụ](#-ví-dụ)
- [Cấu trúc thư mục](#-cấu-trúc-thư-mục)
- [Đóng góp](#-đóng-góp)
- [Giấy phép](#-giấy-phép)

## 💡 Giới thiệu

Google Authenticator sử dụng liên kết `otpauth-migration` để sao lưu và khôi phục mã 2FA. Công cụ này giúp bạn trích xuất secret key từ liên kết đó và hiển thị dưới dạng dễ đọc để có thể sử dụng cho các ứng dụng 2FA khác như Authy, Microsoft Authenticator, v.v.

## 🛠️ Yêu cầu

- Hệ điều hành: Linux, macOS, hoặc Windows (có môi trường hỗ trợ C)
- **`protobuf-c`**: Để làm việc với Protocol Buffers
- **`gcc`**: Trình biên dịch C
- **`make`**: Công cụ tự động hóa quá trình biên dịch

### Cài đặt các yêu cầu trên Ubuntu

```bash
sudo apt update
sudo apt install protobuf-c-compiler libprotobuf-c-dev gcc make
```

## 🚀 Cài đặt

Clone dự án và biên dịch mã nguồn:

```bash
git clone https://github.com/haiphamcoder/g2fa-extractor.git
cd g2fa-extractor
make
```

File thực thi sẽ được tạo trong thư mục `bin/` với tên `g2fa-extractor`.

## 📖 Hướng dẫn sử dụng

Chạy công cụ với liên kết `otpauth-migration`:

```bash
./bin/g2fa-extractor "otpauth-migration://offline?data=<base64_encoded_data>"
```

### Tham số

- **`<base64_encoded_data>`**: Phần dữ liệu sau `data=` trong liên kết `otpauth-migration`.

## 🔍 Ví dụ

```bash
./bin/g2fa-extractor "otpauth-migration://offline?data=CjEKCkhlbGxvId6tvu8SGEV4YW1wbGU6YWxpY2VAZ29vZ2xlLmNvbRoHRXhhbXBsZTAC%3D%3D"
```

### Kết quả

```text
Issuer: Example
Name: alice@google.com
Secret Key: JBSWY3DPEHPK3PXP
```

## 📂 Cấu trúc thư mục

```text
g2fa-secret-extractor/
├── include/                # Chứa các file header (.h)
├── src/                    # Chứa các file mã nguồn (.c)
├── protobuf/               # Chứa file .proto và file biên dịch từ protobuf
├── build/                  # Thư mục lưu file biên dịch (.o)
├── bin/                    # Chứa file thực thi
├── Makefile                # File tự động hóa biên dịch
└── README.md               # Hướng dẫn sử dụng
```

## 🤝 Đóng góp

Chúng tôi luôn hoan nghênh sự đóng góp từ cộng đồng! Để đóng góp, vui lòng:

1. Fork dự án
2. Tạo một nhánh mới (`git checkout -b feature/your-feature`)
3. Thực hiện các thay đổi và commit (`git commit -m 'Add some feature'`)
4. Push nhánh của bạn (`git push origin feature/your-feature`)
5. Tạo Pull Request

## 📄 Giấy phép

Dự án này được cấp phép theo giấy phép MIT. Xem file [LICENSE](./LICENSE) để biết thêm chi tiết.

## 📝 Liên hệ

Nếu bạn có bất kỳ câu hỏi hoặc góp ý nào, vui lòng liên hệ qua:

- Email: [ngochai285nd@gmail.com](mailto:ngochai285nd@gmail.com)
- GitHub: [https://github.com/haiphamcoder](https://github.com/haiphamcoder)
