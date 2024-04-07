SELECT
    players.first_name,
    players.last_name,
    salaries.salary,
    salaries.year,
    performances.year,
    performances."home runs"
FROM
    players
    JOIN salaries ON players.id = salaries.player_id
    JOIN (
        SELECT
            performancesances.player_id,
            performancesances.year,
            SUM(HR) AS "home runs"
        FROM
            performancesances
        GROUP BY
            performancesances.player_id,
            performancesances.year
    ) AS performances ON salaries.player_id = performances.player_id
ORDER BY
    players.id,
    salaries.year DESC,
    performances."home runs" DESC,
    salaries.salary DESC;

    -- Todd Zeile id = 20728
