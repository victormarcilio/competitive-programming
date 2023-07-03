package meetup

import (
	"time"
)

type WeekSchedule int

const (
	random WeekSchedule = iota
	First
	Second
	Third
	Fourth
	Fifth
	Teenth
	Last
)

func Day(wSched WeekSchedule, wDay time.Weekday, month time.Month, year int) int {
	t := time.Date(year, month, 1, 0, 0, 0, 0, time.UTC)

	switch {
	case wSched == Last:
		var lastDay int
		for t.Month() == month {
			if t.Weekday() == wDay {
				lastDay = t.Day()
			}
			t = t.Add(24 * time.Hour)
		}
		return lastDay
	case wSched == Teenth:
		t := time.Date(year, month, 13, 0, 0, 0, 0, time.UTC)
		for t.Weekday() != wDay {
			t = t.Add(24 * time.Hour)
		}
		return t.Day()
	default:
		var counter WeekSchedule
		for {
			if t.Weekday() == wDay {
				counter++
			}

			if counter == wSched {
				break
			}

			t = t.Add(24 * time.Hour)
		}
		return t.Day()
	}
}
