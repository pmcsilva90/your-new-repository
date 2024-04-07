SELECT
    players.first_name,
    players.last_name,
    salaries.salary,
    performances."home runs",
    salaries.year AS "salary year",
    performances.year AS "performance year"
FROM
    players
    JOIN salaries ON players.id = salaries.player_id
    JOIN (
        SELECT
            *,
            SUM(HR) AS "home runs"
        FROM
            performances
        GROUP BY
            performances.year
    ) AS performances ON salaries.year = performances.year
ORDER BY
    players.id,
    salaries.year,
    performances.year
LIMIT
    100;
