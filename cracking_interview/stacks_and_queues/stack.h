#pragma once

#include <memory>
#include <iostream>

namespace NStack {
    template<typename T>
    class Stack {
    private:
        struct StackNode {
            std::unique_ptr<StackNode> Next;
            T Data;

            explicit StackNode(const T &data)
                : Data(data) {}
        };

        std::unique_ptr<StackNode> Top_;
    public:
        Stack() = default;

        Stack(const Stack &other) = delete;

        Stack(std::initializer_list<T> list) {
            for (const T &data: list) {
                Push(data);
            }
        }

        Stack(Stack &&other) noexcept
            : Top_(std::move(other.Top_)) {
        }

        Stack& operator=(Stack&& other) noexcept {
            if (this != &other) {
                Top_ = std::move(other.Top_);
            }
            return *this;
        }

        void Push(const T &data) {
            auto newTop = std::make_unique<StackNode>(data);
            newTop->Next = std::move(Top_);
            Top_ = std::move(newTop);
        }

        void Pop() {
            Top_ = std::move(Top_->Next);
        }

        T& Top() {
            return Top_->Data;
        }

    };
}
