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
#### 요청/응답 공통 규칙
- 모든 요청에는 `action: string`이 포함됩니다.
- OK 응답은 “요청자에게만” 내려가며 형식은 `{"response":"ok","action":"<요청 action>", ...}` 입니다.
- 에러 응답은 공통 포맷만 사용합니다(표에는 에러 코드를 넣지 않습니다).
  - 에러 응답 포맷: `{"response":"error","action":"<요청 action>","code":"<코드>","message":"<설명>"}`

---

#### 요청 API (Client → Server)

| action | **필수 필드 (타입)** | OK 응답 예시 |
|---|---|---|
| `create_room` | `room_title (string)` | `{"response":"ok","action":"create_room","room_id":1,"room_title":"방 이름1","player_id":1,"ready":false}` |
| `find_rooms` | `page (int)` | `{"response":"ok","action":"find_rooms","page":1,"rooms":[{"room_id":1,"room_title":"방 이름1"}, ...]}` |
| `get_room` | `room_id (int)` | `{"response":"ok","action":"get_room","room":{"room_id":1,"room_title":"방 이름1"}}` |
| `join` | `name (string)` | `{"response":"ok","action":"join"}` |
| `join_room` | `room_id (int)` | – | `{"response":"ok","action":"join_room"}` |
| `exit` | `room_id (int)`, `player_id (int)` | `{"response":"ok","action":"exit","player_id":1}` |
| `ready` | `room_id (int)`, `player_id (int)` | `{"response":"ok","action":"ready","player_id":3,"ready":true}` |
| `start_game` | `room_id (int)` | `{"response":"ok","action":"start_game"}` |
| `card_revealed` | `player_id (int)` | `{"response":"ok","action":"card_revealed"}` |
| `press_bell` |`player_id (int)`, `press_time_diff (int, ms)` | `{"response":"ok","action":"press_bell"}` |
| `user_joined` *(alias)* |  `room_id (int)`, `name (string)` | `{"response":"ok","action":"user_joined","player_id":7,"room_id":1}` |
| `penalty_given` | `player_id (int)`, `reason (string)` | `target_ids (int[])`, `penalty_count (int)` | `{"response":"ok","action":"penalty_given"}` |


---

#### 요청에 대한 OK 응답 (Server → 요청자)

| 요청 action | OK 응답 payload (키: 타입) | OK 응답 예시 |
|---|---|---|
| `create_room` | `action:string`, `response:string`, `room_id:int`, `room_title:string`, `player_id:int`, `ready:bool` | `{"response":"ok","action":"create_room","room_id":1,"room_title":"방 이름1","player_id":1,"ready":false}` |
| `find_rooms` | `action`, `response`, `page:int`, `rooms:[{room_id:int, room_title:string}]` | `{"response":"ok","action":"find_rooms","page":1,"rooms":[{"room_id":1,"room_title":"방 이름1"}]}` |
| `get_room` | `action`, `response`, `room:{room_id:int, room_title:string}` | `{"response":"ok","action":"get_room","room":{"room_id":1,"room_title":"방 이름1"}}` |
| `join` | `action`, `response` | `{"response":"ok","action":"join"}` |
| `join_room` | `action`, `response` | `{"response":"ok","action":"join_room"}` |
| `exit` | `action`, `response`, `player_id:int` | `{"response":"ok","action":"exit","player_id":1}` |
| `ready` | `action`, `response`, `player_id:int`, `ready:bool` | `{"response":"ok","action":"ready","player_id":3,"ready":true}` |
| `start_game` | `action`, `response` | `{"response":"ok","action":"start_game"}` |
| `card_revealed` | `action`, `response` | `{"response":"ok","action":"card_revealed"}` |
| `press_bell` | `action`, `response` | `{"response":"ok","action":"press_bell"}` |
| `user_joined` *(alias)* | `action`, `response`, `player_id:int`, `room_id:int` | `{"response":"ok","action":"user_joined","player_id":7,"room_id":1}` |
| `penalty_given` | `action`, `response` | `{"response":"ok","action":"penalty_given"}` |

---

## 브로드캐스트 이벤트 (Server → 관련 클라이언트)

| event action | payload | 예시 |
|---|---|---|
| `user_joined` | `player_id:int`, `name:string` | `{"action":"user_joined","player_id":7,"name":"Alice"}` |
| `user_exited` | `player_id:int` | `{"action":"user_exited","player_id":7}` |
| `ready_changed` | `player_id:int`, `ready:bool` | `{"action":"ready_changed","player_id":3,"ready":true}` |
| `game_started` | `room_id:int`, `players:[{player_id:int, name:string}]` *(선택)* | `{"action":"game_started","room_id":1}` |
| `turn_changed` | `player_id:int` | `{"action":"turn_changed","player_id":2}` |
| `card_revealed` | `player_id:int`, `card:{num:int,type:string}`, `remaining_cards:int` | `{"action":"card_revealed","player_id":3,"card":{"num":3,"type":"banana"},"remaining_cards":11}` |
| `penalty_given` | `player_id:int`, `reason:string`, `distribution:[{from:int,to:int,count:int}]` | `{"action":"penalty_given","player_id":3,"reason":"invalid_bell","distribution":[{"from":3,"to":2,"count":2}]}` |
| `player_lost` | `player_id:int` | `{"action":"player_lost","player_id":2}` |
| `game_winner` | `player_id:int` | `{"action":"game_winner","player_id":1}` |


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
