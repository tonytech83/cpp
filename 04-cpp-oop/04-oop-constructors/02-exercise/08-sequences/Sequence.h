//
// Created by tonytech on 28.08.2025.
//

#ifndef CPP_SEQUENCES_H
#define CPP_SEQUENCES_H

#endif // CPP_SEQUENCES_H

#include <climits>
#include <vector>

template<class T, class Generator>
class Sequence {
    typedef std::vector<T> SequenceContainer;

    SequenceContainer sequence;
    Generator generator;


public:
    class Iterator {
        SequenceContainer &sequence;
        unsigned int index;

        // Requirements:
        // operator * => dereferencing operator
        // operator ++ => forward iterator
        // operator == => comparison operator
        // operator != => comparison operator

    public:
        Iterator(SequenceContainer &sequence, unsigned long index) : sequence(sequence), index(index) {}

        auto operator*() -> T & { return sequence[index]; }

        auto operator++() -> Iterator & {
            index++;
            return *this;
        }

        auto operator==(const Iterator &other) const -> bool {
            // if address of this->sequence is != from address of other.sequence
            if (&this->sequence != &other.sequence)
                return false;

            if (this->isAtTheEnd() && other.isAtTheEnd())
                return true; // both are at the end!

            return this->index == other.index;
        }

        auto operator!=(const Iterator &other) const -> bool { return !(*this == other); }

    private:
        [[nodiscard]] auto isAtTheEnd() const -> bool { return index >= sequence.size(); }
    };

    auto generateNext(int count) -> void {
        while (count--)
            sequence.push_back(generator());
    }

    auto begin() -> Iterator { return Iterator(sequence, 0); }
    auto end() -> Iterator { return Iterator(sequence, ULONG_MAX); }
};
