SELECT
    players.first_name,
    players.last_name,
    salaries.salary,
    salaries.year
FROM
    players
    JOIN salaries ON players.id = salaries.player_id
UNION
SELECT
    performances.year,
    performances.HR
ORDER BY
    players.id,
    salaries.year DESC,
    performances.HR DESC,
    salaries.salary DESC;

-- Todd Zeile id = 20728
