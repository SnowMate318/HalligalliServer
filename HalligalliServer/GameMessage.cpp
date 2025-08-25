#include "GameMessage.h"


json GameMessage::toJson()  {
    json j;
    j["action"] = status;
    j["users"] = json::array();

    for (auto* p : players) {
        if (!p) continue;


        int id = p->getPlayerId();   // 가정: IGamePlayer::getPlayerId()
        std::string name = p->getPlayerName();       // 가정: IGamePlayer::getName()

        int remaining = 0;
        if (auto* deck = p->getDeck()) {
            remaining = deck->getCardCount();
        }

        int cardNum = 0;
        if (frontCards) {
            // 가정: IFrontCards에 이런 메서드가 있음
            if (ICard* c = frontCards->getFrontCardById(id)) {
                cardNum = c->getCardNum();
            }
        }

        j["users"].push_back({
            {"id",               id},
            {"name",             name},
            {"card_num",         cardNum},
            {"remaining_cards",  remaining}
            });
    }

    return j;
}