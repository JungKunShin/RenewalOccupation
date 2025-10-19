# RenewalOccupation
언리얼 전략게임 프로젝트<br><br>

## 🏰 프로젝트 소개
**RenewalOccupation**은 저의 언리얼 첫 작업이었던 **Occupation**의 틀을 가져와 그동안 배웠던 기술들을 사용해, 다시 다듬은 프로젝트입니다.<br>
기존 블루프린트 프로젝트를 C++로 재구현하였습니다.<br>
**문명6**에서 점령이라는 개념만 가져온 4X 전략 게임입니다. 병력이라는 수치를 통해 전투 결과를 판정하고, 종국에 가장 많은 점령지를 보유한 문명이 승리하는 게임입니다.
<br><br>

## 🔗 프로젝트 관련 링크

### 📹 프로젝트 영상 링크<br>

![](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)&nbsp;&nbsp;
- [리뉴얼 후 점령전 플레이영상](https://youtu.be/eJB83VBuzRg "리뉴얼점령전 영상")
- [리뉴얼 전 점령전 플레이영상](https://youtu.be/Kvh-vPBiEpQ "원조점령전 영상")
<br><br><br>

## 📆 개발기간
+ 2025.09.11 ~ 2025.09.27 (2주) <br>
+ 초기개발기간 2024.12.26 ~ 2025.01.08 (2주) <br>

## 🧰 기술 스택 및 환경
![](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![](	https://img.shields.io/badge/unrealengine-%23313131.svg?style=for-the-badge&logo=unrealengine&logoColor=white)
![](https://img.shields.io/badge/Visual_Studio-5C2D91?style=for-the-badge&logo=visual%20studio&logoColor=white)
- Language : C++
- Game Engine : Unreal Engine 5 (C++ / Blueprint 혼합 개발)
- IDE : Visual Studio 2022
- Gameplay Systems :
  - Battle System(BaseStructure(Actor) 기반)
- Data Handling : SaveGame
- VFX / SFX : Sound Wave, Audio Component
- Tools : Blueprint, Material Editor, Media Player etc
<br><br>

## 🔧 주요 기술
1. ⚒️ 전투 결과 판단
   - 각 점령지 플레이어 병력, AI 병력을 비교하여 누구의 승리인지 판단
   - 한 문명이 다른 문명들에 비해 압도적으로 보냈는지를 확인하여, 병력 소멸 또는 본진 복귀 결정<br><br>
   [전투 전] 🔨
     ![전투결과1](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/BeforeBattle.png)<br>
     ![전투결과2](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/BeforeBattleMap.png)<br><br>
   [전투 후] 🛠️
     ![전투결과3](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/AfterBattle.png)<br>
     ![전투결과4](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/AfterBattleMap.png)<br><br>
---
2. 🌏 점령지 소유권
   - 전투 결과 판단을 통해, 해당 전투 승리 문명을 식별하여 해당하는 구조물과 점령색 설정<br><br>
   [점령 전] 🌍
     ![점령지소유권1](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/BeforeOcc.png)<br><br>
   [점령 후] 🌎
     ![점령지소유권2](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/AfterOcc.png)<br><br>
---
3. 📹 미디어 플레이어 재생
   - MediaPlayer(재생장치 역할)와 FileMediaSource(영상)를 기반으로 구현된 영상재생 시스템
   - MediaPlayer만으로는 음성 출력이 안되므로, MediaSoundComponent을 통해 영상 오디오 재생 구현
   - 게임 종국에 승리, 무승부, 패배를 판단하여 해당하는 영상 재생<br><br>
   [승리] 😄
     ![승리](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/Victory.png)<br><br>
   [무승부] 😐 
     ![무승부](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/Draw.png)<br><br>
   [패배] 😭
     ![패배](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/Lose.png)<br><br>
---
4. ✨ 세이브/로드
   - SaveGame인 'GameInfoSaveGame','SoundSaveGame'을 통해 게임 정보와 볼륨 정보 저장
   - Tag에 대한 정보도 저장해, 각 점령지 정보들은 Tag를 통해 알맞게 로드
   - IsEnd 변수를 통해 게임이 끝났는지를 판단하여, 다시 로드 방지<br><br>
   [로드 불가능] ❌
     ![로드X](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/NotLoad.png)<br><br>
   [세이브] ✅
     ![세이브](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/Save.png)<br><br>
   [로드 가능] :o:
     ![로드가능](https://github.com/JungKunShin/RenewalOccupation/blob/main/Image/Load.png)<br><br>
