# Forgot Your Password? 

Partial writeup; full version will come later.

We are given a generator that appears to randomly generate values for a combo key. We also know the last value, `hsctfissocoolwow`. After reversing the function, a possible version of the code can look like this:

```
def rotl(x, k):
        return (x << k) | (x >> (64 - k))

def next():
        s0 = s[0]
        s1 = s[1]
        res = (s0 + s1) & bit64

        s1 ^= s0
        s[0] = rotl(s0, 55) ^ s1 ^ (s1 << 14)
        s[1] = rotl(s1, 36)
        s[0] &= bit64
        s[1] &= bit64
        return res & bit64

```

Doing some Googling, we find that the RNG is actually Xoroshiro128+, a performant PRNG that is *not* cryptographically secure. Now, you could simply reverse all of the binary options then use z3 to narrow down the possible seeds, but with clever recon you could find these links:

[Main post on "cracking" xoroshiro128+](https://lemire.me/blog/2017/08/22/cracking-random-number-generators-xoroshiro128/)
[Source code](https://github.com/lemire/crackingxoroshiro128plus)
[Source for prev() function](https://www.reddit.com/r/programming/comments/6va3a8/cracking_random_number_generators_xoroshiro128/dlywdrs/)

As well, the seed we are given is 16 bytes long, or two consecutive outputs of the PRNG. To solve, we can place the string into little-endian format as `0x7373696674637368 0x776f776c6f6f636f`, then run `xoroshiftall.py` to solve for the (only!) seed. From there, you can run the provided `prev()` function a few times to reverse the PRNG state, then simple generate your final key.

Hope you enjoyed :)