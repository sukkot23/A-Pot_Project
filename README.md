# A-Pot_Project
Team A-Pot 'Smart Flower Pot' Project

**팀 에이포트의 '스마트 LED 화분' 프로젝트**
   
```
2021.05.26 - 아두이노 소스코드 업로드
2021.06.02 - 소스코드 주석 추가
           - 모델링 파일 업로드
           - 결과물 사진 업로드
2021.07.17 - 결선도 수정 및 README 수정 
```   
</br>
   
## Thumbnail
Normal Version | ឵Improved version
:-------------------------:|:-------------------------:
<img src="https://user-images.githubusercontent.com/56511728/120421870-133fd200-c3a2-11eb-9ed1-893e7228f79a.jpg" width="300"> | <img src="https://user-images.githubusercontent.com/56511728/126022360-261c9634-c92e-429c-9d68-74a2b3bcb670.jpg" width="347">


## 제품 설명 (Product Guide)
```
스마트 LED 화분은 두 가지의 모드를 보유하고 있습니다

1. LED 모드 (빛 감지 모드)
  
  LED 모드는 광 센서를 통해 감지된 빛의 양(lux)에 따라
  어두울 시 LED가 자동으로 활성화 됩니다
  
  Lux 값 500 이상부터 빨간색 LED가 점등,
  Lux 값 650 이상부터 파란색 LED가 점등되며,
  
  Lux값 499 이하부터 모든 LED 소등,
  Lux값 249 이하부터 LCD 디스플레이 백라이트가 소등됩니다
  
  
2. 슬립 모드 (휴면 모드)

  슬립 모드는 24시간 가동되는 스마트 화분의 전력소비량을
  낮추기 위해, 식물에게 지속적인 광에 의한 스트레스를 주는 행위를 방지하기 위한 모드입니다
  
  슬립 모드 상태에서는 광 센서를 통해 감지된 빛의 양에 관계없이,
  LED와 LCD 디스플레이 백라이트가 비활성화된 상태로 지속됩니다
  
  
스마트 LED 화분은 전원 연결점을 기준으로
3시간 간격으로 자동으로 1번 모드(LED 모드)와 2번 모드(슬립 모드)를
번갈아가며 모드 교체를 하게 됩니다
```
### LCD 상태 설명
Emoji | ឵Description
:---:|:---:
<img src="https://user-images.githubusercontent.com/56511728/126022623-b8c04b03-1919-4893-b4ca-5ff32db606b3.png"> | 밝기레벨 650이상 일 경우 </br> 파란LED, 빨간LED 활성화
<img src="https://user-images.githubusercontent.com/56511728/126022630-748dac90-9089-4207-b687-cc1460b69d66.png"> | 밝기레벨 500이상 일 경우 </br> 빨간LED만 활성화
<img src="https://user-images.githubusercontent.com/56511728/126022635-996e090f-f16b-4e45-aff0-ddcb5e269a78.png"> | 밝기레벨 499이하 일 경우 </br> 모든 LED 비활성화
<img src="https://user-images.githubusercontent.com/56511728/126022638-95f4f86b-2761-4611-a455-d2f4a6dfed49.png"> | 밝기레벨 249이하 일 경우 </br> LCD 백라이트 꺼짐


</br>

## 소스코드 (Source Code)
https://github.com/sukkot23/A-Pot_Project/blob/master/sketch_aPot.ino

## 모델링 (3D Model)
https://github.com/sukkot23/A-Pot_Project/tree/master/3D_Objects

## 결선도 (Wiring Diagram)
https://github.com/sukkot23/A-Pot_Project/tree/master/Wiring_Diagram

</br>

## 참고자료

아두이노 참고 - 영문 (Arduino Reference En)   
https://www.arduino.cc/reference/en/   
아두이노 참고 - 한글 (Arduino Reference Ko)   
https://www.arduino.cc/reference/ko/

LCD 라이브러리 (LiquidCrystal Library)   
https://www.arduino.cc/en/Reference/LiquidCrystal

LCD 커스텀 문자열 생성 사이트 (LCD Custom Character Generator Site)   
https://maxpromer.github.io/LCD-Character-Creator/

아두이노 범퍼 모델링 (Arduino Bumper 3D Object)   
https://www.thingiverse.com/thing:26237
