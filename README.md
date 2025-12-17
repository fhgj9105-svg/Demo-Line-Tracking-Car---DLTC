# Demo-Line-Tracking-Car---DLTC
My homework<br>
This code is used for testing and studying. Therefore, It do not have the format that an official project should have had!<br>
This program using PID control althogism to adjust position of the car when it is running in straing line and when it is turning in lagre angel. Besides that, it's have "turnLeft" and "turnRight" function to process 45 to 90 degrees angles.<br>
Flow chart: Will be updated soon.<br>
Components: 1 Lipo battery, 4 TT motors, 5 infered sensors, 2 L298N boards, 1 Breadboard, wires<br>
Wiring: Will be update soon.<br>
Defect: <br>
*Do not process intersections so it can go straing on or turn right or turn left completely depending on error's value before.<br>
*The Kp, Ki, Kd coefficients still not optimized.<br>
*Each motor have different velocity although it is provided the same PWM. So you need to use "BUTRU" macro to fix them.<br>
Note: *You should use 2 L298N board because of the heat will be very high when PID control is working.<br>
      *Do not care about analogRead because it still has some problems in it's syntax.<br>
**PLEASE ATTENTION**<br>
**IF IT'S WORKING, DO NOT TOUCH IT!**<br>
Bài tập của tôi<br>
Đoạn code này được sử dụng cho mục đích kiểm tra và học tập. Vì vậy, nó không có định dạng đầy đủ như một dự án chính thức!<br>
Chương trình này sử dụng thuật toán điều khiển PID để điều chỉnh vị trí của xe khi nó chạy thẳng và khi rẽ với góc lớn. Bên cạnh đó, chương trình có các hàm "turnLeft" và "turnRight" để xử lý các góc từ 45 đến 90 độ.<br>
Sơ đồ khối: Sẽ được cập nhật sớm.<br>
Linh kiện: 1 pin LiPo, 4 động cơ TT, 5 cảm biến hồng ngoại, 2 mạch L298N, 1 breadboard, dây nối<br>
Đấu dây: Sẽ được cập nhật sớm.<br>
Khuyết điểm: <br>
*Không xử lý giao lộ nên xe có thể đi thẳng, rẽ phải hoặc rẽ trái hoàn toàn tùy theo giá trị lỗi trước đó.<br>
*Các hệ số Kp, Ki, Kd vẫn chưa được tối ưu.<br>
*Mỗi động cơ có tốc độ khác nhau mặc dù được cấp cùng một mức PWM. Vì vậy bạn cần sử dụng macro "BUTRU" để cân chỉnh chúng.<br>
Lưu ý: *Bạn nên sử dụng 2 mạch L298N vì nhiệt độ sẽ rất cao khi điều khiển PID hoạt động.<br>
      *Không cần quan tâm đến hàm analogRead vì cú pháp của nó vẫn còn một số vấn đề.<br>
**VUI LÒNG CHÚ Ý**<br>
**NẾU NÓ ĐANG HOẠT ĐỘNG, ĐỪNG ĐỘNG VÀO!**
                      
