//
// Created by Roy Skullestad on 4/9/26.
//

#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include<vector>

template<typename T>
class GameEventHandler {
public:
    virtual ~GameEventHandler()=default;
protected:
    template<typename U> friend class GameEvent;
    virtual void Handle(const T& value)=0;
};

template<typename T>
class GameEvent final {
public:
    void operator+=(GameEventHandler<T>* handler) {
        AddHandler(handler);
    }
    void AddHandler(GameEventHandler<T>* handler) {
        handlers_.push_back(handler);
    }

    void operator-=(const GameEventHandler<T>* handler) {
        RemoveHandler(handler);
    }

   void RemoveHandler(const GameEventHandler<T>* handler) {
        auto head = handlers_.begin();
        for(;head!=handlers_.end();++head) {
            if(*head == handler) {
               break;
            }
        }
        if(head!=handlers_.end()) {
            handlers_.erase(head);
        }
    }

    void operator()(const T& value) {
        Invoke(value);
    }

    void Invoke(const T& value) {
        for (auto& handler: handlers_) {
            handler->Handle(value);
        }
    }
private:
    std::vector<GameEventHandler<T>*> handlers_;
};
#endif //GAME_EVENT_H
