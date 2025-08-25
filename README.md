# 할리갈리 게임


### 개요

주변 사람들과 즐길 수 있는 할리갈리 게임의 서버를 구현하였습니다.

객체지향 설계 강의에서 배운 내용을 토대로 실제로 구현했던 서버를 재설계하여 구현하였습니다.  




### 클래스 다이어그램

<img width="3153" height="1057" alt="할리갈리_최종 drawio" src="https://github.com/user-attachments/assets/a0519679-855c-49fc-a517-c3448547374f" />  



#### 요청 처리
<img width="1162" height="1031" alt="요청_처리" src="https://github.com/user-attachments/assets/4de5af6c-253e-4662-9f45-24df4d71d18d" />  


* 13개의 사용자 요청 처리 (방 찾기, 게임 시작, 게임 진행 관련)
* 요청이 많아짐에 따라 수신부의 역할이 너무 커졌음
    * 요청 별로 구현체를 다르게 만드는 기법을 이용하여 수신부의 역할을 분할시킴  



#### 로비, 방
<img width="1116" height="350" alt="룸_로비" src="https://github.com/user-attachments/assets/23f24452-2d08-4ac9-8cca-2b5b873de0fd" />  



#### 게임 진행
<img width="1565" height="657" alt="게임" src="https://github.com/user-attachments/assets/7f39a3f7-881b-46f9-93ef-74a1454ea9b3" />  


* 클라이언트의 요청에 따라 여러 객체(카드, 덱, 플레이어, 종)와의 상호작용이 많아짐
* 객체 간 상호 호출 발생
   * 이를 해결하기 위해 요청 별로 관련있는 객체들을 이어주는 역할을 담당하는 인터페이스(Game) 추가  



### 요청 명세


| **Action** | **설명** | **Data 예시** |
| --- | --- | --- |
| join | 이름 전송 | { "name": "Alice" } |
| start_game | 방장 게임 시작 | {} |
| ready | 준비 완료 | {} |
| open_card | 카드 오픈 요청 | {} |
| press_bell | 벨 누름 | { "press_time_diff": 230 } |
| find_room | 생성된 방 전체 조회 | {} |
| find_room | 방 id로 조회 | {”id”: 1} | 
| join_room | 방 참여 | {”id”:1} |  



| **Action** | **설명** | **Data 예시** |
| --- | --- | --- |
| user_joined | 1명 입장 | { "id": 2, "name": "Alice" } |
| user_left | 1명 퇴장 | { "id": 2 } |
| current_users | 현재 유저 목록 | { "users": [ { "id": 1, "name": "Host" }, ... ] } |
| game_started | 게임 시작 | {} |
| card_revealed | 카드 공개됨 | { "id": 2, "card": { "num": 3, "type": "banana" }, "remaining_cards": 11 } |
| turn_changed | 턴 넘김 | { "id": 3 } |
| round_winner | 라운드 승리 | { "id": 1 } |
| penalty_given | 패널티 발생 | { "id": 3, "reason": "invalid_bell" } |
| player_lost | 플레이어 탈락 | { "id": 2 } |
| game_winner | 게임 승리 | { "id": 1 } |
| all_ready | 모두 준비 완료 (방장에게만) | {} |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |



#### CREATE_ROOM ( 방 생성)

- Request
    
    ```c
    {"action": CREATE_ROOM, "room_title": "방 이름"
    }
    ```
    
- Response
    1. 정상 응답
        
        ```c
        {
        	"response": OK, 
        	"action": CREATE_ROOM, 
        	"room_id": 1, 
        	"room_title": "방 이름1",
        	"id":1, 
        	"ready":false
        }
         // 요청한 유저에게 전달
        ```
        
    2. 비정상 응답
        
        ```c
        {"response": ERROR, "action": CREATE_ROOM, "message": "더이상 방을 생성할 수 없습니다."} 
        
        {"response": ERROR, "action": CREATE_ROOM, "message": "예상하지 못한 오류"}
         // 요청한 유저에게 전달
        ```
        

#### FIND_ROOM ( 방 찾기)

- Request
    
    ```c
    {"action": FIND_ROOM, "page": 1}
    ```
    
- Response
    1. 정상 응답
        
        ```c
        {"response":OK, "action":FIND_ROOM, "page":1, "rooms": [
        	{"room_id": 1, "room_title": "방 이름1"}
        	{"room_id": 2, "room_title": "방 이름2"}
        	{"room_id": 3, "room_title": "방 이름3"}
        	{"room_id": 4, "room_title": "방 이름4"}
        	{"room_id": 5, "room_title": "방 이름5"}
        	{"room_id": 6, "room_title": "방 이름6"}
        	{"room_id": 7, "room_title": "방 이름7"}
        	{"room_id": 8, "room_title": "방 이름8"}
        	{"room_id": 9, "room_title": "방 이름9"}
        	{"room_id": 10, "room_title": "방 이름10"}
        ]}
        
         // 요청한 유저에게 전달
         // 페이지 1: id 1~10
         // 페이지 2: id 11~20
         // 페이지 3: id 21~30
         // 3페이지까지 만들 예정
        ```
        
    2. 비정상 응답
        
        ```c
        
        {"response": ERROR, "action": FIND_ROOM, "message": "예상하지 못한 오류"}
         // 요청한 유저에게 전달
        ```
        

#### JOIN (방 입장)

- Request
    
    ```c
    {"action": JOIN, "room_id": 1}
    ```
    

- Response
    1. 정상 응답
        
        ```c
        {"response":OK, "action": USER_JOINED, "id":3, "name": "Host3", "ready":false} 
         // 룸 안에 있는 모든 플레이어에게 전달
        ```
        
        ```c
        {"response":OK, "action": USER_JOINED, "id":1, "name": "Host1", "ready":true} 
        {"response":OK, "action": USER_JOINED, "id":2, "name": "Host2", "ready":false} 
        {"response":OK, "action": USER_JOINED, "id":3, "name": "Host3", "ready":false} 
         // 요청한 유저에게 방 안에 있는 모든 플레이어 정보 전달
        ```
        
    2. 비정상 응답
        
        ```c
        {"response": ERROR, "action": JOIN, "message": "방이 다 찼습니다."} 
        // 참가하려는 방의 인원이 4명인 경우
        
        {"response": ERROR, "action": JOIN, "message": "예상하지 못한 오류."} 
         // 요청한 유저에게 전달
        ```
        

#### EXIT (방 퇴장)

- Request
    
    ```c
    {"action": EXIT, "room_id":1, "room_player_id":1}
    ```
    

- Response
    1. 정상 응답
        
        ```c
        {"response":OK, "action": EXIT, "id":1, "name": "Host1"} 
         // 룸 안에 있는 모든 플레이어에게 전달
        ```
        
    2. 비정상 응답
        
        ```c
        
        {"response": ERROR, "action": EXIT, "message": "예상하지 못한 오류."} 
         // 요청한 유저에게 전달
        ```
        

#### READY (준비)

- Request
    
    ```c
    {"action": READY, "room_id": 1, "room_player_id": 3}
    ```
    

- Response
    1. 정상 응답
        
        ```c
        {"response":OK, "action": READY, "id":3, "name": "Host3", "ready":true} 
         // 룸 안에 있는 모든 플레이어에게 전달
        ```
        
    2. 비정상 응답
        
        ```c
        {"response": ERROR, "action": READY, "message": "예상하지 못한 오류."} 
         // 요청한 유저에게 전달
        ```
        

#### GAME_STARTED (게임 시작)

- Request
    
    ```c
    {"action": GAME_STARTED, "room_id":}
    ```
    
- Response
    1. 정상 응답
        
        ```c
        {"response":OK, "action": GAME_STARTED, "users": [
        	{"id": 1, "name": "Host1", "card_num"0, "remaining_cards":14},
        	{"id": 2, "name": "Host2", "card_num"0, "remaining_cards":14},
        	{"id": 3, "name": "Host3", "card_num"0, "remaining_cards":14},
        	{"id": 4, "name": "Host4", "card_num"0, "remaining_cards":14},
        ], "current_turn_id": 1} // 모두에게 이 메세지 전달
        
        // card_num
        // 0 빈 카드
        // 1~5 사과
        // 6~10 바나나
        // 11~15 포도
        // 16~20 수박
        
        ```
        
    2. 비정상 응답
        
        ```c
        {"response": ERROR, "action": GAME_STARTED, "message": "2명 이상이 있어야 게임을 진행할 수 있습니다."} 
        //1명일때 게임 시작을 누른 경우
        {"response": ERROR, "action": GAME_STARTED, "message": "모두가 ready 상태여야 합니다."} 
        //모두가 ready를 누르지 않은 경우
        {"response": ERROR, "action": GAME_STARTED, "message": "예상하지 못한 오류"}
         // 요청한 유저에게 이 메세지 전달
        ```
        

#### CARD_REVEALED (카드 내기)

- Request
    
    ```c
    {"action": CARD_REVEALED, "room_id":1, "id": 1}
    ```
    
- Response
    1. 정상 응답
        
        ```c
        {"response":OK, "action": CARD_REVEALED, "users": [
        	{"id": 1, "name": "Host1", "card_num"5, "remaining_cards":13},
        	{"id": 2, "name": "Host2", "card_num"0, "remaining_cards":14},
        	{"id": 3, "name": "Host3", "card_num"0, "remaining_cards":14},
        	{"id": 4, "name": "Host4", "card_num"0, "remaining_cards":14},
        ], "current_turn_id": 2, "player_death":0} 
        // 모두에게 이 메세지 전달, 턴 넘김 적용
        
        // player_death
        // 0 죽은 사람 없음
        // 1~4 죽은사람 id
        
        ```
        
    
    1. 정상 응답(플레이어 죽을 경우)
        
        ```c
        {"response":OK, "action": CARD_REVEALED, "users": [
        	{"id": 1, "name": "Host1", "card_num"2, "remaining_cards":0},
        	{"id": 2, "name": "Host2", "card_num"7, "remaining_cards":1},
        	{"id": 3, "name": "Host3", "card_num"12, "remaining_cards":1},
        	{"id": 4, "name": "Host4", "card_num"16, "remaining_cards":1},
        ], "current_turn_id": 2, "player_death":1}
        // 모두에게 이 메세지 전달
        // 1번이 낼 카드가 없어서 죽은 경우
        
        // player_death
        // 0 죽은 사람 없음
        // 1~4 죽은사람 id
        
        ```
        
    2. 비정상 응답
        
        ```c
        {"response": ERROR, "action": CARD_REVEALED, "message": "자신의 차례가 아닙니다."} 
        //자신의 차례가 아닌 경우
        
        {"response": ERROR, "action": CARD_REVEALED, "message": "살아있는 사람만 벨을 누를 수 있습니다."} 
        //죽은 플레이어가 카드를 낼 경우
        
        {"response": ERROR, "action": CARD_REVEALED, "message": "누군가가 벨을 눌렀습니다."} 
        //벨 연산이 진행중인 경우
        
        {"response": ERROR, "action": CARD_REVEALED, "message": "예상하지 못한 오류"}
         // 요청한 유저에게 이 메세지 전달
        ```
        

#### PRESS_BELL (벨 누르기)

- Request
    
    ```c
    {"action": PRESS_BELL, "room_id":1, "id":1, "press_time_diff": 230}
    ```
    
- Response
    1. 정상 응답(라운드 승리)
        
        ```c
        {"response":OK, "action": PRESS_BELL, "users": [
        	{"id": 1, "name": "Host1", "card_num"0, "remaining_cards":13},
        	{"id": 2, "name": "Host2", "card_num"0, "remaining_cards":14},
        	{"id": 3, "name": "Host3", "card_num"0, "remaining_cards":15},
        	{"id": 4, "name": "Host4", "card_num"0, "remaining_cards":14},
        ], "current_turn_id": 3, "winner_id":3} 
        // 모두에게 이 메세지 전달
        // 처음으로 요청이 온 시점으로부터 3초후에 답장옴
        
        ```
        
    
    1. 비정상 응답
        
        ```c
        {"response": ERROR, "action": PRESS_BELL, "message": "살아있는 사람만 종을 누를 수 있습니다."} 
        // 죽은 플레이어가 종을 누른 경우
        
        {"response": ERROR, "action": PRESS_BELL, "message": "예상하지 못한 오류"}
         // 요청한 유저에게 이 메세지 전달
        ```
        

#### PENALTY_GIVEN (패널티 적용)

- Request
    
    ```c
    {"action": PENALTY_GIVEN, "room_id":1, "id":1}
    ```
    
- Response
    1. 정상 응답
        
        ```c
        {"response":OK, "action": PENALTY_GIVEN, "users": [
        	{"id": 1, "name": "Host1", "card_num"3, "remaining_cards":11},
        	{"id": 2, "name": "Host2", "card_num"0, "remaining_cards":15},
        	{"id": 3, "name": "Host3", "card_num"0, "remaining_cards":15},
        	{"id": 4, "name": "Host4", "card_num"0, "remaining_cards":15},
        ], "current_turn_id": 2, "penalty_id":1, "player_death": 0}
        // 모두에게 이 메세지 전달
        // 요청즉시 답장옴
        
        ```
        
    
    1. 정상응답(플레이어 죽을 경우)
        
        ```c
        {"response":OK, "action": PENALTY_GIVEN, "users": [
        	{"id": 1, "name": "Host1", "card_num"3, "remaining_cards":0},
        	{"id": 2, "name": "Host2", "card_num"0, "remaining_cards":15},
        	{"id": 3, "name": "Host3", "card_num"0, "remaining_cards":15},
        	{"id": 4, "name": "Host4", "card_num"0, "remaining_cards":15},
        ], "current_turn_id": 2, "penalty_id":1, "player_death": 1}
        // 모두에게 이 메세지 전달
        // 요청즉시 답장옴
        
        // player_death
        // 0 죽은 사람 없음
        // 1~4 죽은사람 id
        ```
        
    
    1. 비정상 응답
        
        ```c
        
        {"response": ERROR, "action": PENALTY_GIVEN, "message": "예상하지 못한 오류"}
         // 요청한 유저에게 이 메세지 전달
        ```
        

#### EXIT_IN_GAME (게임 중 나감)

- Request
    
    플레이어의 프로세스가 종료되었을 때 자동 호출
    
- Response
    
    ```c
    {"response":OK, "action": EXIT_IN_GAME, "users": [
    	{"id": 1, "name": "Host1", "card_num"3, "remaining_cards":14},
    	{"id": 2, "name": "Host2", "card_num"0, "remaining_cards":15},
    	{"id": 3, "name": "Host3", "card_num"0, "remaining_cards":0},
    	{"id": 4, "name": "Host4", "card_num"0, "remaining_cards":15},
    ], "current_turn_id": 2, "player_death": 3}
    
    // 현재 턴인 플레이어가 나가면 턴 이동하기
    ```
    

#### GAME_WIN (게임 승리)

- Request
    
    승리 요건 충족되었을 때 자동 호출
    
- Response
    
    ```c
    {"response": OK, "action": GAME_WIN , "id":1}
    ```
