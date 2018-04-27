module PowerOfTwo where
import Data.Bits

-- Determines if @n is a power of two
--
-- Determines if @n is a power of two by
-- taking advantage of the fact that the
-- log base 2 of any power of two will
-- result in a whole number.
-- Note that this method is inaccurate beyond 2^37
--
-- param n : any number
-- return  : true if @n is a power of two, false if not
poweroftwoLog :: Integer -> Bool
poweroftwoLog n = 
    fromIntegral (floor (logBase 2 (fromInteger n)) :: Integer) == (logBase 2 (fromInteger n))

-- Determines if @n is a power of two
--
-- Determines if @n is a power of two by
-- taking advantage of the fact that
-- powers of two have only one bit flipped.
-- Hence, if the result of a bitwise 'and'
-- operation on @n and @n-1 results in 0,
-- then @n is a power of two.
--
-- param n : any whole number
-- return  : true if @n is a power of two, false if not
poweroftwo :: Integer -> Bool
poweroftwo n = ((n - 1) .&. n) == 0

