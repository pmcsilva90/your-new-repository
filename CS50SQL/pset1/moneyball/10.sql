SELECT
    players.first_name,
    players.last_name,
    salaries.salary,
    performances."home runs",
    salaries.year
FROM
    players
    JOIN salaries ON players.id = salaries.player_id
    JOIN (
        SELECT
            performances.player_id,
            performances.year,
            SUM(HR) AS "home runs"
        FROM
            performances
        GROUP BY
            performances.player_id,
            performances.year
    ) AS performances ON salaries.year = performances.year
ORDER BY
    players.first_name,
    players.last_name,
    salaries.year;
