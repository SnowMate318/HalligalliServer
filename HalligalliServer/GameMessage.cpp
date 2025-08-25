#include "GameMessage.h"


json GameMessage::toJson()  {
    json j;
    j["action"] = status;
    j["users"] = json::array();

    for (auto* p : players) {
        if (!p) continue;


        int id = p->getPlayerId();   // ����: IGamePlayer::getPlayerId()
        std::string name = p->getPlayerName();       // ����: IGamePlayer::getName()

        int remaining = 0;
        if (auto* deck = p->getDeck()) {
            remaining = deck->getCardCount();
        }

        int cardNum = 0;
        if (frontCards) {
            // ����: IFrontCards�� �̷� �޼��尡 ����
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