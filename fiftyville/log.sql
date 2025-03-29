-- Keep a log of any SQL queries you execute as you solve the mystery.

-- I read the description tryng to gather infos regarding the theft
SELECT description
FROM crime_scene_reports
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND street = 'Humphrey Street';

-- Since the report cites a bakery I try to look at
-- the security logs
SELECT hour, minute, activity, license_plate
FROM bakery_security_logs
WHERE day = 28
    AND month = 7
    AND year = 2024;

SELECT DISTINCT license_plate
FROM bakery_security_logs;


-- Since three interviews are cited in the reports I
-- look into them
SELECT name, transcript
FROM interviews
WHERE day = 28
    AND month = 7
    AND year = 2024;

-- Eugene, Raymond and Ruth gave important infos so I
-- write down their names.

-- And I select the transcripts of their interviews
SELECT transcript
FROM interviews
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND name = 'Raymond' OR (name = 'Eugene' AND transcript LIKE '%bakery%') OR name = 'Ruth';

-- I look at the atm transactions since it's cited
-- in one of the interviews
SELECT account_number, transaction_type, amount
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street'
ORDER BY id ASC;


-- Phone calls were cited
SELECT caller, receiver, duration, id
FROM phone_calls
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND duration < 60
ORDER BY id ASC;


-- From the interview
SELECT account_number
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street'


-- I find the person_id of the people that
-- made a transaction in that day, street, etc.

SELECT person_id
FROM bank_accounts
WHERE account_number IN
(SELECT account_number
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street');

-- I retrieve people's data from bank
-- accounts' ids

SELECT name, phone_number, passport_number, license_plate
FROM people
WHERE id IN
(SELECT person_id
FROM bank_accounts
WHERE account_number IN
(SELECT account_number
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street'));

-- I want to find the infos of the people that
-- executed a bank transaction and had a call of less than 60s

SELECT name, phone_number, passport_number, receiver, license_plate
FROM people
JOIN phone_calls
ON caller = phone_number
WHERE people.id IN
(SELECT person_id
FROM bank_accounts
WHERE account_number IN
(SELECT account_number
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street'))
AND phone_calls.duration < 60
AND phone_calls.day = 28;

-- I need the id of the origin airport ID
SELECT id, abbreviation, full_name
FROM airports
WHERE city = 'Fiftyville';

-- I look at the flights since I know
-- that they wanna flee the next day

SELECT destination_airport_id, hour, minute, id
FROM flights
WHERE day = 29
    AND month = 7
    AND year = 2024
    AND origin_airport_id = 8;


-- I check the passengers of the flights / transaction / phone call
SELECT name, passengers.passport_number
FROM passengers
JOIN people
ON people.passport_number = passengers.passport_number
JOIN phone_calls
ON caller = phone_number
WHERE flight_id IN
(SELECT id
FROM flights
WHERE day = 29
    AND month = 7
    AND year = 2024
    AND origin_airport_id = 8)
AND people.id IN
(SELECT person_id
FROM bank_accounts
WHERE account_number IN
(SELECT account_number
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street'))
AND phone_calls.duration < 60
AND phone_calls.day = 28;


-- Look at the destinations of these four suspects
-- | Kenny  | 9878712108
 -- New York City | 4
-- | Taylor | 1988161715
 -- New York City | 4
-- | Diana  | 3592750733
-- | Bruce  | 5773159633
 -- New York City | 4

SELECT flight_id
FROM passengers
WHERE passport_number IN
(SELECT passengers.passport_number
FROM passengers
JOIN people
ON people.passport_number = passengers.passport_number
JOIN phone_calls
ON caller = phone_number
WHERE flight_id IN
(SELECT id
FROM flights
WHERE day = 29
    AND month = 7
    AND year = 2024
    AND origin_airport_id = 8)
AND people.id IN
(SELECT person_id
FROM bank_accounts
WHERE account_number IN
(SELECT account_number
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street'))
AND phone_calls.duration < 60
AND phone_calls.day = 28);


SELECT destination_airport_id
FROM flights
WHERE id IN
(SELECT flight_id
FROM passengers
WHERE passport_number IN
(SELECT passengers.passport_number
FROM passengers
JOIN people
ON people.passport_number = passengers.passport_number
JOIN phone_calls
ON caller = phone_number
WHERE flight_id IN
(SELECT id
FROM flights
WHERE day = 29
    AND month = 7
    AND year = 2024
    AND origin_airport_id = 8)
AND people.id IN
(SELECT person_id
FROM bank_accounts
WHERE account_number IN
(SELECT account_number
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street'))
AND phone_calls.duration < 60
AND phone_calls.day = 28));


SELECT city, id
FROM airports
WHERE id IN
(SELECT destination_airport_id
FROM flights
WHERE id IN
(SELECT flight_id
FROM passengers
WHERE passport_number IN
(SELECT passengers.passport_number
FROM passengers
JOIN people
ON people.passport_number = passengers.passport_number
JOIN phone_calls
ON caller = phone_number
WHERE flight_id IN
(SELECT id
FROM flights
WHERE day = 29
    AND month = 7
    AND year = 2024
    AND origin_airport_id = 8)
AND people.id IN
(SELECT person_id
FROM bank_accounts
WHERE account_number IN
(SELECT account_number
FROM atm_transactions
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND atm_location = 'Leggett Street'))
AND phone_calls.duration < 60
AND phone_calls.day = 28)));



SELECT city, id
FROM airports
WHERE id IN
(SELECT destination_airport_id
FROM flights
WHERE id IN
(SELECT flight_id
FROM passengers
WHERE passport_number = 5773159633));


-- | Kenny  | 9878712108
 -- New York City | 4
-- | Taylor | 1988161715
 -- New York City | 4
-- | Bruce  | 5773159633
 -- New York City | 4

-- Retrieve the license plates
SELECT license_plate
FROM people
WHERE name = 'Taylor';

--  30G67EN Kenny

-- 94KL13X Bruce

-- 1106N58 Taylor

SELECT hour, minute, activity
FROM bakery_security_logs
WHERE license_plate = '94KL13X'
    AND day = 28
    AND month = 7
    AND year = 2024;

-- Kenny has never been in the bakery, Bruce and Taylor have been for two hours
-- Taylor ten minutes later than Bruce


-- Bruce has stolen the DUCK since it was in the parking lot 10 minutes
-- after the theft instead Taylor was still inside.
-- Kenny has helped Bruce since Bruce called someone outside before leaving.

-- Bruce's number
SELECT phone_number
FROM people
WHERE name = 'Bruce';

-- (367) 555-5533

SELECT receiver
FROM phone_calls
WHERE day = 28
    AND month = 7
    AND year = 2024
    AND duration < 60
    AND caller = '(367) 555-5533';

-- Receiver: (375) 555-8161
SELECT name
FROM people
WHERE phone_number = '(375) 555-8161';

-- It's Robin's number. I wrongly assumed that also the accomplice
-- would have escaped with the thief.
-- From the intervies I can be sure that the accomplice is Robin,
-- since he's the guy whom Bruce calls.
